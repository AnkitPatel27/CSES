#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
 
void dfs(int node,int par1,int deep,vvi &par,vvi &adj,vi &depth){
    depth[node] = deep;
    

    for(int nxt :adj[node]){
        if(nxt!=par1){
            dfs(nxt,node,deep+1,par,adj,depth);
        }
    }
}

int goUp(int a,int k,vvi &par){
    for(int i=0;i<=20;i++){
        int res = (1<<i & k);
        if(res){
            a = par[a][i];
        }
    }
    return a;
}

int findLca(int a,int b,vvi &par,vi &depth){
    if(depth[b]>depth[a]){
        swap(a,b);
    }

    a = goUp(a,depth[a]-depth[b],par);
    if(a==b){
        return a;
    }

    for (int i = 20; i >= 0; i--)
    {
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
    int n,q;
    cin>>n>>q;

    vi depth(n+1,0);
    vvi par(n+1,vi (21,0));
    vvi adj(n+1);

    for (int i = 2; i <=n; i++)
    {
        int x;
        cin>>x;
        par[i][0] = x; 
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    for (int i = 1; i < 21; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            par[j][i] = par[par[j][i-1]][i-1];
        }
        
    }
    
    
    dfs(1,1,0,par,adj,depth);

    for (int i = 0; i < q; i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<findLca(x,y,par,depth)<<endl;    
    }
    
    return 0;
}