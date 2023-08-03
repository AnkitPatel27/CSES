#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void dfs(int node,int par,vector <vector <int>>  &adj,vector <int> &done){
    for(int nxt:adj[node]){
        if(nxt!=par){
            dfs(nxt,node,adj,done);
            if(done[nxt]==0 && done[node]==0){
                cnt+=1;
                done[nxt]=done[node]=1;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;

    vector <vector <int>> adj(n+1);

    for (int i = 1; i <=n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector <int> done(n+1,0);
    
    dfs(1,0,adj,done);
    cout<<cnt<<endl;
    return 0;
}