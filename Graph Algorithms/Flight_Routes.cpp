#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    int k;
    cin>>k;

    vector <vector <pair<int,long long>>> adj(n+1);
    for (int i = 0; i < m; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
    }

    priority_queue<long long> bes[n+1];
    priority_queue <pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
    vector <long long> dist(n+1,INT_MAX);
    dist[1] = 0;
    bes[1].push(0);
    q.push({0,1});

    while(!q.empty())
    {
        auto front = q.top();
        int fromNode = front.second;
        q.pop();
        if(front.first > bes[fromNode].top()){
           continue; 
        }
        for (int i = 0; i < adj[fromNode].size(); i++)
        {
            int toNode = adj[fromNode][i].first;
            long long w = adj[fromNode][i].second + front.first;
            // cout<<"toNode : "<<toNode<<" : w "<<w<<endl;
            if(bes[toNode].size()<k){
                bes[toNode].push(w);
                q.push({w,toNode});
            }
            else if(w < bes[toNode].top()){
                bes[toNode].pop();
                bes[toNode].push(w);
                q.push({w,toNode});
            }
        }
        

    }
    
    // cout<<"bes : "<<bes[n].size()<<endl;
    vector<long long> ans;
	while (bes[n].size()) {
		ans.push_back(bes[n].top());
		bes[n].pop();
	}
	reverse(ans.begin(),ans.end());

    for (auto a : ans) cout << a << " ";
    
    return 0;
}