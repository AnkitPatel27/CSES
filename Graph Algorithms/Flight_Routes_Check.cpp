#include <bits/stdc++.h>
using namespace std;
 
void dfs(int node,vector <vector <int>> &adj,vector <int> &vis,vector <int> &visOrder){
    if(vis[node]){
        return;
    }
    // cout<<node<<endl;
    vis[node] = 1;
    for(int nxt:adj[node]){
        dfs(nxt,adj,vis,visOrder);
    }
    visOrder.push_back(node);

}

void rdfs(int node,vector <vector <int>> &adj,vector <int> &vis){
    if(vis[node]){
        return;
    }
    vis[node] = 1;
    for(int nxt:adj[node]){
        rdfs(nxt,adj,vis);
    }

}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector <vector <int>> adj(n+1),radj(n+1);

    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        radj[y].push_back(x);
    }
    
    vector <int> vis(n+1,0),rvis(n+1,0),visOrder;
    for (int i = 1; i <=n; i++)
    {
        if(vis[i]==0){
            dfs(i,adj,vis,visOrder);
        }
    }
    
    vector <int> order;
    for (int i = visOrder.size() - 1; i >= 0; i--)
    {
        // cout<<"Order : "<<visOrder[i]<<endl;
        if(rvis[visOrder[i]]==0){
            order.push_back(visOrder[i]);
            rdfs(visOrder[i],radj,rvis);
        }
    }
    
    if(order.size()>1){
        cout<<"NO\n";
        cout<<order[1]<<" "<<order[0]<<endl;
    }
    else{
        cout<<"YES";
    }

    return 0;
}