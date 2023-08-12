#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)

vi ans;
vector<vector<pair<int,int>>> adj((int)1e5+2);
vi visEdge((int)2e5+1);

void dfs(int node,int par){
    // cout<<node<<" : "<<par<<endl;
    int a,nxt;
    for (int i = adj[node].size()-1; i>=0 ; i--)
    {
        nxt = adj[node][i].first;
        a = adj[node][i].second;
        adj[node].pop_back();
        if(visEdge[a]==0){
            visEdge[a] = 1;
            dfs(nxt,node);
        }   
        i = min(i,(int)adj[node].size());
    }

    ans.push_back(node);

} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int m;
    cin>>m;

    vi degree(n+1,0);

    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,i});
        adj[y].push_back({x,i});
        degree[x]++;
        degree[y]++;
    }
    // oneDeg = degree[1];
    
    FOR(1,n,1){
        if((degree[i]&1)){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }

    dfs(1,-1);
    // cout<<"reached \n";

    if(ans.size()==0 || ans.size()!=m+1){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}