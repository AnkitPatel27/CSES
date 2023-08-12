#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
 
vvi adj((int)2e5+1), par((int)2e5+1,vi(21,0));
vi depth((int)2e5+1,0);

void dfs(int node,int par1,int deep){
    depth[node] = deep;
    par[node][0] = par1;

    for(int nxt: adj[node]){
        if(nxt!=par1){
            dfs(nxt,node,deep+1);
        }
    }
}

int goUp(int a,int k ){
    for (int i = 0; i < 21; i++)
    {
        int res = (1<<i)&k;
        if(res){
            a = par[a][i];
        }
    }
    return a;
}


int findDistance(int a,int b){
    if(depth[b]>depth[a]){
        swap(a,b);
    }
    int ans = depth[a]-depth[b];
    a = goUp(a,depth[a]-depth[b]);
    if(a==b){
        return ans;
    }
    // cout<<"got here \n";
    int at,bt;
    for (int i = 20; i >= 0; i--)
    {
        at = par[a][i];
        bt = par[b][i];

        if(at!=bt){
            ans += 2*(1<<i);
            a = at;
            b = bt;
        }
    }

    return 2+ans;
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n,m;
    cin>>n>>m;


    for (int i = 1; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    dfs(1,0,1);

    for (int i = 1; i < 21; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            par[j][i] = par[par[j][i-1]][i-1];
        }
        
    }
    

    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<findDistance(x,y)<<"\n";
    }
    

    return 0;
}