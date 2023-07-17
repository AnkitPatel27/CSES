#include <bits/stdc++.h>
using namespace std;
 
void djkstra(int StartNode,int n,vector <vector <pair <int,long long>>> &adj,vector <long long> &dist){
    // cout<<"dist : "<<StartNode<<"\n";
    vector <int> vis(n+1,0);
    priority_queue <pair<long long,int>,vector <pair<long long,int>>,greater <pair<long long,int>>> q;
    q.push({0,StartNode});
    dist[StartNode] = 0;

    int i =0;
    while(i<n && !q.empty()){
        auto top = q.top();
        if(vis[top.second]==0){
            vis[top.second]=1;
            int fromNode = top.second;
           
            // cout<<"Node : "<<fromNode<<" : "<<dist[fromNode]<<"\n";

            for(int j =0 ;j<adj[fromNode].size();j++){
                int toNode = adj[fromNode][j].first;
                long long weight = adj[fromNode][j].second;
                if(vis[toNode]==0 && (dist[toNode]>weight+dist[fromNode])){
                    dist[toNode]=weight+dist[fromNode];
                    q.push({dist[toNode],toNode});
                }
            }

            i++;
        }
        q.pop();
    }
}


int main(){
    
    int n,m;
    cin>>n>>m;

    vector <vector <pair <int,long long>>> adj(n+1);
    vector <vector <pair <int,long long>>> radj(n+1);

    for (int i = 0; i < m; i++)
    {
        int x,y;
        long long c;
        cin>>x>>y;
        cin>>c;
        adj[x].push_back({y,c});
        radj[y].push_back({x,c});
    }
    long long inf = 1e17;
    vector <long long> startDist(n+1,inf);
    vector <long long> endDist(n+1,inf);

    djkstra(1,n,adj,startDist);
    djkstra(n,n,radj,endDist);

    long long ans = inf;
    for (int i = 1; i <=n; i++)
    {
        int curNode = i;
        for (int j = 0; j < adj[i].size(); j++)
        {
            // cout<<"out \n";
            int ToNode = adj[i][j].first;
            long long w = adj[i][j].second;
            ans = min(ans,startDist[curNode]+endDist[ToNode] + (w/2));
        }
        
    }
    
    cout<<ans<<endl;
    
    return 0;
}