#include <bits/stdc++.h>
using namespace std;
 
void dfs(int node,vector <int> &vis,vector <vector <int>> &adj,vector <int> &visOrder){
    if(vis[node]){
        return;
    }

    vis[node] =1;
    for(int nxt:adj[node]){
        dfs(nxt,vis,adj,visOrder);
    }

    visOrder.push_back(node);
}

void rdfs(int node,int king,vector <int> &rvis,vector <vector <int>> &radj){
    if(rvis[node]!=0){
        return;
    }

    rvis[node] =king;

    for(int nxt:radj[node]){
        rdfs(nxt,king,rvis,radj);
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
            dfs(i,vis,adj,visOrder);
        }
    }
    
    int king = 1;
    for (int i = visOrder.size() - 1; i >= 0; i--)
    {
        int node = visOrder[i];
        if(rvis[node]==0){
            rdfs(node,king,rvis,radj);
            king++;
        }
    }
    
    cout<<king-1<<"\n";
    for (int i = 1; i <=n; i++)
    {
        cout<<rvis[i]<<" ";
    }
    

    return 0;
}