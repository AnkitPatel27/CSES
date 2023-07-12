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
    
    // cout<<"input Done\n";
    queue<int> q;
    
    q.push(1);
    vis[1] = -1;
    bool flag = true;
    while(!q.empty() && flag){
        int node = q.front();
        if(vis[n]!=0){
            flag = false;
            break;
        }
        // cout<<"node : "<<node<<endl;
        q.pop();
        for (int i = 0; i < adj[node].size(); i++) {
            if(vis[adj[node][i]]==0){
                // cout<<adj[node][i]<<endl;
                vis[adj[node][i]] = node;
                q.push(adj[node][i]);
            }
        }
        
    }
    
    if(flag){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    
    int k = n;
    vector <int> ans;
    ans.push_back(k);
    while(vis[k]!=-1){
        k = vis[k];
        ans.push_back(k);
    }
    cout<<ans.size()<<endl;
    for (int i = ans.size()-1 ; i >=0 ; i--) {
        cout<<ans[i]<<" ";
    }
    
    
    
    return 0;
}