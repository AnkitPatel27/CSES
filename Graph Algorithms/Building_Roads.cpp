#include <bits/stdc++.h>
using namespace std;
string s = "";
void dfs(int city,vector<vector<int>> &adj,vector<int> &vis){
    
    if(vis[city] == 1 ){
        return;
    }
    
    vis[city] = 1;
    
    for (int i = 0; i < adj[city].size(); i++) {
        dfs(adj[city][i],adj,vis);    
    }
    
}
 
int main(){
    
    int n,m;
    cin>>n>>m;
    
    vector<vector <int>> adj(n+1);
    vector <int> vis(n+1,0);
    
    for (int i = 0; i < m; i++) {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector <int> heads;
    
    for (int i = 1; i <= n; i++) {
        if(vis[i]==0){
            heads.push_back(i);
            dfs(i,adj,vis);
        }
    }
    
    cout<<heads.size()-1<<endl;
    
    int k = heads[0];
    for (int i = 1; i < heads.size(); i++) {
        cout<<k<<" "<<heads[i]<<endl;
    }
    
    
    return 0;
}
