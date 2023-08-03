#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector <vector <pair<int,long long>>> adj(n+1);
    vector <long long> dist(n+1,LONG_LONG_MAX),routes(n+1,0),minFlight(n+1,LONG_LONG_MAX),maxFlight(n+1,0);

    for(int i=0;i<m;i++){
        int x,y;
        long long z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
    }

    priority_queue <pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> q;

    q.push({0,1});
    dist[1]=0;
    routes[1] = 1;
    minFlight[1] = 0;
    maxFlight[1] = 0;
    long long pi =1e9+7;

    vector <int> vis(n+1,0);
    while(!q.empty()){
        pair<int,int> p=q.top();
        q.pop();
        int u=p.second;
        if(vis[u]==1)
            continue;
        
        vis[u] = 1;
        for(auto j:adj[u]){
            
            if(dist[u]+j.second==dist[j.first]){
                routes[j.first]+=routes[u];
                routes[j.first]%=pi;
                minFlight[j.first] = min(1+minFlight[u],minFlight[j.first]);
                maxFlight[j.first] = max(1+maxFlight[u],maxFlight[j.first]);
            }
            else if(dist[u]+j.second<dist[j.first]){
                dist[j.first]=dist[u]+j.second;
                routes[j.first] = routes[u];
                minFlight[j.first] = 1+minFlight[u];
                maxFlight[j.first] = 1+maxFlight[u];
                q.push({dist[j.first],j.first});
            }
        }
    }

    cout<<dist[n]<<" "<<routes[n]<<" "<<minFlight[n]<<" "<<maxFlight[n];

    return 0;
}

