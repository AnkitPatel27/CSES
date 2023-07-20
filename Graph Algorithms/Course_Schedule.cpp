#include <bits/stdc++.h>
using namespace std;

void dfs(int i,vector <vector <int>> &adj,vector <int> &indegree,vector <int> &vis, vector<int> &ans){
    if(vis[i]!=0 || indegree[i]!=0){
        return;
    }
    vis[i]=1;
    ans.push_back(i);
    for(auto j : adj[i]){
        // cout<<"i -> "<<i<<" j "<<j<<"j : "<<indegree[j]<<endl;
        indegree[j]--;
        // cout<<"i -> "<<i<<" j "<<j<<indegree[j]<<endl;
        dfs(j,adj,indegree,vis,ans);
    }
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector <vector <int>> adj(n+1);
    vector <int> indegree(n+1,0),vis(n+1,0);
    vector<int> ans;

    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }

    for (int i = 1; i <=n; i++)
    {
        if(indegree[i]==0 && vis[i]==0){
            // cout<<"started\n";
            dfs(i,adj,indegree,vis,ans);
        }
    }
    
    if(ans.size()!=n){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(auto a:ans){
            cout<<a<<" ";
        }
    }
    
    
    return 0;
}