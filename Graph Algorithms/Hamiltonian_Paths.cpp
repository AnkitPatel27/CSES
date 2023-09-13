#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
int n,m;
vvi adj(21);
ll dp[(1<<20)+1][21];
ll mod = (ll)1e9+7;
int k;
ll dfs(int node,int par,int mask){
    if(node == n){
        if(k == mask){
            return 1;
        }   
        if(node == n){
            return 0;
        }
    }
 
    mask = mask | (1<<(node-1));
 
    if(dp[mask][node]!=-1){
        // cout<<"oh oh\n";
        return dp[mask][node];  
    }   
 
    ll ans = 0;
 
    for(int nxt:adj[node]){
        if((mask & (1<<(nxt-1)))==0){
            ans+=dfs(nxt,node,mask);
            ans%=mod;
        }
    }
 
 
    return dp[mask][node] = ans;
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    k = pow(2,n-1)-1;
    memset(dp,-1,sizeof(dp));
    
    
    FOR(1,m,1){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }
 
    ll ans = dfs(1,1,0);
    cout<<ans;
    return 0;
}