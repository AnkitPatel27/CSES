#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
 
int timer = 1; 

void dfs(int node,int par1,vvi &adj,vi &start,vi &end){
    start[node] = timer;
    timer+=1;
    for(int nxt :adj[node]){
        if(nxt!=par1){
            dfs(nxt,node,adj,start,end);
        }
    }
    end[node] = timer-1;
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

int findLca(int a,int b,vvi &par,vi &start,vi &end){
    if(end[a]>end[b]){
        swap(a,b);
    }

    if(start[a]<=start[b] && end[b]<=end[a]){
        return a;
    }
    // cout<<a<<" : "<<b<<endl;
    for (int i = 20; i >= 0; i--)
    {
        int ga = par[a][i];
        if((start[ga]<=start[b] && end[b]<=end[ga]) || ga==0){
            
        }
        else{
            a = ga;
        }
    }

    // cout<<a;
    return par[a][0];

}



int main(){
    int n,q;
    cin>>n>>q;

    vi start(n+1,0),end(n+1,0);
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
    
    // for (int i = 1; i <=n; i++)
    // {
    //     for (int j = 0; j < 21; j++)
    //     {
    //         cout<<par[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    dfs(1,1,adj,start,end);

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<start[i+1]<<" ";
    // }
    // cout<<endl;
    
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<end[i+1]<<" ";
    // }
    // cout<<endl;

    start[0] = 1000000;
    for (int i = 0; i < q; i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<findLca(x,y,par,start,end)<<endl;    
    }
    
    return 0;
}