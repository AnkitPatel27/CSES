#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin>>n>>m;

    vector <pair<int,pair<int,long long>>> edge(m);
    
    for (int i = 0; i < m; i++)
    {
        int a,b;
        long long c;
        cin>>a>>b;
        cin>>c;
        edge[i] = {a,{b,c}};
    }
    
    long long ninf = -1e17;
    vector <long long> dist(n+1,ninf);
    dist[1] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // edge j from 
            int FromNode = edge[j].first;
            int ToNode = edge[j].second.first;
            long long weight = edge[j].second.second;
            if(dist[FromNode]!=ninf){
                if(dist[ToNode]==ninf){
                    dist[ToNode] = weight + dist[FromNode];
                    // cout<<"edge "<<j<<" dist : "<<dist[ToNode]<<endl;
                }
                else if(dist[ToNode]<weight+dist[FromNode]){
                    dist[ToNode] = weight+dist[FromNode];
                    // cout<<"edge "<<j<<" dist : "<<dist[ToNode]<<endl;
                }
            }
        }
        
    }
    
    long long ans = dist[n];
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // edge j from 
            int FromNode = edge[j].first;
            int ToNode = edge[j].second.first;
            long long weight = edge[j].second.second;
            if(dist[FromNode]!=ninf){
                if(dist[ToNode]==ninf){
                    dist[ToNode] = weight + dist[FromNode];
                }
                else if(dist[ToNode]<weight+dist[FromNode]){
                    if(ToNode==n){
                        cout<<-1;
                        return 0;
                    }
                    dist[ToNode] = (-1ll)*ninf;
                }
            }
        }
        
    }

    // if(dist[n] == ans){
        cout<<dist[n];
        // return 0;
    // }




    return 0;
}