#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
int n;
vi powt(16,1);
vvi adj(32768+10,vi(2,0));
string ans = "";
int cnt = 1;
void dfs(int node){
    // int temp = cnt++;
    for (int i = 0; i < 2; i++)
    {
        if(adj[node][i]==0){
            // cout<<node<<" : "<<temp<<" : "<<i<<endl;
            int ntemp = node;
            adj[ntemp][i]=1;
            int msb = ntemp&powt[n-2];
            if(msb){
                ntemp = ntemp - powt[n-2];
            }
            ntemp = ntemp*2;
            ntemp += i;
            dfs(ntemp);
            ans.push_back(i+48);
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    
    if(n==1){
        cout<<"10"<<endl;
        return 0;
    }
    for (int i = 1; i < 16; i++)
    {
        powt[i] = powt[i-1]*2;
    } 

    dfs(0);
    cout<<ans;
    for (int i = 0; i < n-1; i++)
    {
        cout<<ans[i];
    }
    
    


    return 0;
}