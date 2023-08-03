#include <bits/stdc++.h>
using namespace std;
 
void dfs(int i,vector <vector <int>>  &adj,vector <int> &vis){
    if(vis[i]==1){
        return;
    }
    vis[i]=1;
    for(auto j : adj[i]){
        dfs(j,adj,vis);
    }
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    
    vector <vector <int>> adj(n+1);
    vector <int> indegree(n+1,0),vis(n+1,0);

    for (int i = 1 ;i<=m;++i){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }

    dfs(1,adj,vis);
    if(vis[n]==0){
        cout<<"0"<<endl;
        return 0;
    }

    vector <long long> ways(n+1,0ll);
    queue<int> q;
    for (int i = 1; i <=n; i++)
    {
        if(indegree[i]==0){
            q.push(i);
        }
    }
    ways[1]=1;
    long long p = 1e9+7;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto j :adj[u]){
            ways[j]+=ways[u];
            ways[j]%=p;
            indegree[j]--;
            if(indegree[j]==0){
                q.push(j);
            }
        }
    }
    
    cout<<ways[n]<<endl;
    

    return 0;
}