#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>

vvi adj((int)2e5+1),par((int)2e5+1,vi (21,0));
vi depth((int)2e5+1,0),path((int)2e5+1,0),ans((int)2e5+1,0); 

void dfs(int node,int par1,int deep){    
    depth[node] = deep;
    par[node][0] = par1;
    for(int nxt:adj[node]){
        if(nxt!=par1){
            dfs(nxt,node,deep+1);
        }
    }
}

void dfs2(int node,int par1){
    // cout<<"node : "<<node<<endl;
    ans[node] += path[node];

    for(int nxt:adj[node]){
        if(nxt!=par1){
            dfs2(nxt,node);
            ans[node]+=ans[nxt];
        }
    }
}

int goUp(int a,int k){
    for (int i = 0; i < 21; i++)
    {
        int res = (1<<i)&k;
        if(res){
            a = par[a][i];
        }
    }
    return a;
}

int findLca(int a,int b){
    if(depth[b]>depth[a]){
        swap(a,b);
    }
    
    a = goUp(a,depth[a]-depth[b]);

    if(a==b){
        return a;
    }

    for (int i = 20; i >=0; i--){
        int ga = par[a][i];
        int gb = par[b][i];
        if(ga!=gb){
            a = ga;
            b = gb;
        }
    }
    return par[a][0];
}


int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int m;
    cin>>m;

    for (int i = 1; i <n; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0,1);

    for (int j = 1; j < 21; j++)
    {
        for (int i = 1; i <=n; i++)
        {
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
       
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        int lca = findLca(a,b);
        // cout<<lca<<endl;
        path[lca]--;
        path[a]++;
        path[b]++;
        if(lca!=1){
            path[par[lca][0]]--;
        }

    }
    
    dfs2(1,0);
    // cout<<"Done 2 \n";
    for (int i = 1; i <=n; i++)
    {
        cout<<ans[i]<<" ";
    }
    

    return 0;
}