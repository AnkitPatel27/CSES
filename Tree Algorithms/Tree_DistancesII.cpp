#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int,int>

ll totalDist = 0; 
ll distdfs(int node,int par ,int dist,vl &nodeBelow,vvi &adj){
    totalDist+=dist;
    ll below = 0;
    for(int nxt:adj[node]){
        if(nxt!=par){
             below += distdfs(nxt,node,dist+1,nodeBelow,adj);
        }
    }
    nodeBelow[node]=below+1ll;
    return nodeBelow[node];
}

void totalDistdfs(int node,int par,vl &nodeBelow,vvi &adj,vl &dist,ll &n){
    // cout<<"node : "<<node<<endl;
    if(node==1){
        for(int nxt:adj[node]){
            if(nxt!=par){
                totalDistdfs(nxt,node,nodeBelow,adj,dist,n);
            }
        }
    }
    else{
        ll nodeAbove = n - nodeBelow[node];
        dist[node] = dist[par] - nodeBelow[node] + nodeAbove;
        for(int nxt:adj[node]){
            if(nxt!=par){
                totalDistdfs(nxt,node,nodeBelow,adj,dist,n);
            }
        }
    }
}

int main(){
     ll n;
    cin>>n;

    vvi adj(n+1);

    for (int i = 1; i <=n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vl nodeBelow(n+1,0),dist(n+1,0);
    ll below = distdfs(1,0,0,nodeBelow,adj);
    dist[1] = totalDist;
    totalDistdfs(1,0,nodeBelow,adj,dist,n);
    // cout<<totalDist<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<dist[i+1]<<" ";
    }
    
    return 0;
}