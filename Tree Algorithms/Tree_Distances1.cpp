#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>

int len = 0;
int d1 = 1;
int len2 = 0;
int d2 = 0;

void dfs(int node,int par,int dist,vvi &adj){
    if(dist>len){
        len = dist;
        d1 = node;
    }
    
    for(int nxt: adj[node]){
        if(nxt!=par){
            dfs(nxt,node,dist+1,adj);
        }
    }
}

void dfsd1(int node,int par,int dist,vvi &adj,vi &distd1){
    if(dist>len2){
        len2 = dist;
        d2 = node;
    }
    
    for(int nxt: adj[node]){
        if(nxt!=par){
            dfsd1(nxt,node,dist+1,adj,distd1);
        }
    }
    distd1[node] = dist;
}

void dfsd2(int node,int par,int dist,vvi &adj,vi &distd2){    
    for(int nxt: adj[node]){
        if(nxt!=par){
            dfsd2(nxt,node,dist+1,adj,distd2);
        }
    }
    distd2[node] = dist;
}


int main(){
    int n;
    cin>>n;

    vvi adj(n+1);

    for (int i = 1; i <=n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //dist node 
    vi distd1(n+1,0),distd2(n+1,0);

    dfs(1,0,0,adj);
    dfsd1(d1,0,0,adj,distd1);
    dfsd2(d2,0,0,adj,distd2);
    for(int i =1;i<=n;i++){
        cout<<max(distd1[i],distd2[i])<<" ";
    }

    

    return 0;
}
