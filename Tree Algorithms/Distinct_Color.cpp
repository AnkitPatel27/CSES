#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)

vi color((int)2e5+1);
vi start((int)2e5+1),end((int)2e5+1),a((int)2e5+1),lastColor((int)2e5+1,0);
vvi adj((int)2e5+1);
int timer = 1;

// void updateFenwick(int index,int newVal){
//     if(index<=0){
//         return ;
//     }
//     for (int i = index; i <=n; i+=(i&(-i)))
//     {
//         a[i]+=newVal;
//     }
    
// }

// vi distinctColors((int)2e5+1);
set<int> dfs(int node,int par){
    start[node] = timer++;
   
    for(int nxt:adj[node]){
        if(nxt!=par){
            dfs(nxt,node);
        }
    }

    end[node] = timer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    FOR(1,n,1){
        cin>>color[i];
    }

    FOR(1,n-1,1){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,1);
    vector <vector <pair<int,int>>> ; query((int)2e5+1);

    for (int i = 1; i <=n; i++)
    {
        query[end[i]].push_back({start[i],i});
    }
       
    map <int,int> mp;
    vi ans((int)2e5+1,0);
    for (int i = 1; i <=n; i++)
    {
        if(mp.count(color[i])>0){
            updateFen(mp[color[i]],-1);
        }    

        mp[color[i]] = 1;
        updateFen(i,1);

        for(auto a: query[i]){
            int start = a.first;
            int end = a.second.first;
            int index = a.second.second;
            
            ans[i] = queryFen(end)-queryFen(start-1);

        }

    }
    

    for (int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<" ";
    }
    

    return 0;
}