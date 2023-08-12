#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
ll p = (int)1e9+7;

typedef struct node{
    bool Flag;
    node *nxt[26];
    node(){
        Flag = false;
        for (int i = 0; i < 26; i++)
        {
            nxt[i] = NULL;
        }
        
    }

    void insert(string s){
        node *cur =  this;
        for (int i = 0; i < s.size(); i++)
        {
            if(cur->nxt[s[i]-'a']==NULL){
                node *newnode = new node();
                cur->nxt[s[i]-'a'] = newnode;
            }
            cur = cur->nxt[s[i]-'a'];
        }
        
        cur->Flag = true;
    }

    void search(int k,string &s,vl &dp,int n){
        // cout<<"k : "<<k<<n<<endl;
        node *cur =  this;
        for (int i = k;i < n; i++)
        {
            // cout<<s[i]<<" ";
            if(cur->nxt[s[i]-'a']!=NULL){
                cur  = cur->nxt[s[i]-'a'];
                if(cur->Flag){
                    dp[k]+=dp[i+1];
                    dp[k]%=p;
                }
            }
            else{
                return;
            }
        }
        
    }


} node;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

     string s;
    cin>>s;

    int n;
    cin>>n;
    
    node *Root = new node();

    FOR(0,n-1,1){
        string temp;
        cin>>temp;
        Root->insert(temp);
    }

    int sn = s.size();
    vl dp(sn+1,0);
    dp[sn] = 1;
    for (int i = sn-1; i >= 0; i--)
    {
        Root->search(i,s,dp,sn);
    }
    
    cout<<dp[0]<<endl;

    return 0;
}