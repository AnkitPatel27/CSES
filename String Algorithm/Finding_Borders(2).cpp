#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;

    int n = s.size();
    
    vi pi(n,0);

    int i = 1;
    while(i<n){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        pi[i] = j;
        i++;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<pi[i]<<" ";
    // }
    // cout<<endl;

    vi ans;
    int j = pi[n-1];
    while(j>0){
        ans.push_back(j);
        j = pi[j-1];
    }
    
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout<<ans[i]<<" ";
    }
    
    
    return 0;
}