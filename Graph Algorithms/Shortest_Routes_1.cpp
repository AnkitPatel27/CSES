#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin>>n>>m;

    vector <vector <pair<int,long long>>> conn(n+1);

    for (int i = 0; i < m; i++)
    {
        int a,b;
        long long c;
        cin>>a>>b>>c;
        conn[a].push_back({b,c});
    }

    vector<long long> dist(n+1,LLONG_MAX),vis(n+1,0);
    dist[1] = 0;
    int i = 1;
    //dist node
    priority_queue <pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> q;
    q.push({0,1});
    // vis[1] = 1;
    while(i<n){
        auto top = q.top();
        if(vis[top.second]==0){
            
            vis[top.second] = 1;

            // cout<<"i : \n";
            for (int j = 0; j < conn[top.second].size(); j++)
            {
                int curNode = conn[top.second][j].first;
                if(vis[curNode]==0 && dist[curNode]>(dist[top.second]+conn[top.second][j].second)){
                    dist[curNode] = (dist[top.second]+conn[top.second][j].second);
                    q.push({dist[curNode],curNode});
                }
            }
            
            i++;
        }
        q.pop();

    }

    for (int i = 1; i <= n ; i++)
    {
        cout<<dist[i]<<" ";
    }
    
    

    return 0;
}