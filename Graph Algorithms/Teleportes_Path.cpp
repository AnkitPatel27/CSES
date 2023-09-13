#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define vpp vector <vector <pair<int,int>>>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)

int n, m;
vpp adj((int)1e5+3);
vi vis((int)2e5+5,0);
vi path;

void dfsEuler(int node){
    // cout<<node<<endl;
    for (int i = adj[node].size()-1; i >=0; i--)
    {
        int nxt = adj[node][i].first;
        int index = adj[node][i].second;
        adj[node].pop_back();
        if(vis[index]==0){
            vis[index] = 1;
            dfsEuler(nxt);
        }
        i = min(i,(int)adj[node].size());
    
    }
    
    path.push_back(node);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    vi indegree(n+2,0),outdegree(n+2,0);

    // cout<<n<<" : "<<m<<endl;
    int edgeI = 0;
    FOR(1,m,1){
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,edgeI++});
        indegree[y]++;
        outdegree[x]++;
    }
    
    adj[n+1].push_back({1,edgeI++});
    indegree[1]++;
    outdegree[n+1]++;
    adj[n].push_back({n+1,edgeI++});
    indegree[n+1]++;
    outdegree[n]++;


    for (int i = 1; i <=n; i++)
    {
        if(indegree[i]!=outdegree[i]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    

    dfsEuler(n+1);


    if(edgeI==path.size()-1 ){
        for (int i = path.size() - 2; i >= 1; i--)
        {
            cout<<path[i]<<" ";
        }
        
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }


    return 0;
}