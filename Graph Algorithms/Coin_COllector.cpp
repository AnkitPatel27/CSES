#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<long long>

void dfs(int node,vi &vis,vi &visOrder,vvi &adj){
    if(vis[node]){
        return;
    }
    vis[node] = 1;
    for(auto nxt : adj[node]){
        if(!vis[nxt])
            dfs(nxt,vis,visOrder,adj);
    }
    visOrder.push_back(node);
}


void dfs2(int node,vi &vis,vvi &adj,int cnt){
    if(vis[node]){
        return;
    }
    vis[node] = cnt;
    for(auto nxt : adj[node]){
        dfs2(nxt,vis,adj,cnt);
    }
}

ll DP(int node,vector<long long> &dp,vll &weights,vvi &graph){
    if(dp[node]!=-1){
        return dp[node];
    }

    ll ans = 0;
    for(auto nxt:graph[node]){
        ans = max(ans,DP(nxt,dp,weights,graph));
    }
    ans+=weights[node];
    return dp[node]=ans;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    
    vll coin(n+1);
    vvi adj(n+1),radj(n+1);
    vi vis(n+1,0),visOrder;

    for (int i = 1 ;i<=n;++i){
        cin>>coin[i];
    }

    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        radj[y].push_back(x);
    }

    for (int i = 1; i <=n; i++)
    {
        if(vis[i]==0){
            dfs(i,vis,visOrder,adj);
        }
    }


    vis = vi(n+1,0);
    vi comps;
    int cnt = 1;
    for (int i = visOrder.size() - 1; i >= 0; i--)
    {
        int node =  visOrder[i];
        if(vis[i]==0){
            dfs2(node,vis,radj,cnt);
            comps.push_back(node);
            cnt++;
            
        }
    }
    
    vll sccWeights(cnt+1,0);
    for (int i = 1; i <=n; i++)
    {
        sccWeights[vis[i]]+=coin[i];
    }
    
    vvi graph(cnt+1);
    for (int i = 1; i <=n; i++)
    {
        for(auto j:adj[i]){
            if(vis[i]!=vis[j])
                graph[vis[i]].push_back(vis[j]);
        }
    }
    // cout<<"count :"<<cnt<<" \n";

    ll ans = 0;
    vll dp(cnt+1,-1);
    for (int i = 1; i <=cnt; i++)
    {
        ans = max(ans,DP(i,dp,sccWeights,graph));
    }
    
    
    cout<<ans<<endl;

    return 0;
}
 