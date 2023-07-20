#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    
    vector <pair <int,pair<int,long long>>> edges(m);

    for (int i = 0; i < m; i++)
    {
        cin>>edges[i].first>>edges[i].second.first>>edges[i].second.second;
    }

    vector <long long> dist(n+1,0); 
    vector <long long> par(n+1,-1); 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int fromNode = edges[j].first;
            int toNode = edges[j].second.first;
            long long w = edges[j].second.second;
            // cout<<fromNode<<" : "<<toNode<<" : "<<w<<endl;
            if(dist[toNode]>w+dist[fromNode]){
                dist[toNode] = w+dist[fromNode];
                par[toNode] = fromNode;
            }

        }
        
    }

    // for (int i = 0; i <=n; i++)
    // {
    //     cout<<dist[i]<<" ";
    // }
    // cout<<endl;
    
    int lastNode = -1;

    for (int i = 0; i < m; i++)
    {
        int fromNode = edges[i].first;
        int toNode = edges[i].second.first;
        long long w = edges[i].second.second;

        if(dist[toNode]>w+dist[fromNode]){
            dist[toNode]=w+dist[fromNode];
            par[toNode] = fromNode;
            lastNode = toNode;
        }

    }

    if(lastNode==-1){
        cout<<"NO\n";
        return 0;
    }
    vector <int> cycle;
    set<int> s;
    cycle.push_back(lastNode);
    s.insert(lastNode);
    int x = par[lastNode];
    while(s.find(x)==s.end()){
        cycle.push_back(x);
        s.insert(x);
        x = par[x];
    }
    cycle.push_back(x);

    
    cout<<"YES\n";
    int cycleNode = cycle[cycle.size()-1];
    cout<<cycleNode<<" ";
    for (int i = cycle.size() - 2; i >= 0; i--)
    {
        if(cycleNode==cycle[i]){
            break;
        } 
        cout<<cycle[i]<<" ";

    }
    cout<<cycleNode<<" ";
    
    



    




    return 0;
}