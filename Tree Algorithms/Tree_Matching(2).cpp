#include <bits/stdc++.h>
using namespace std;

void dp(int node,int par,vector <vector <int>> &adj,vector <int> &dp1.vector <int> &dp2){
    int take=0,notTake=0;
    for(int nxt:node){
        if(nxt!=par){
            notTake += max(dp1[nxt],dp2[nxt]);
        }
    }

    dp2[node] = notTake

    for(int nxt:node){
        if(nxt!=par){
            take = max(take,1+dp2[nxt]+dp2[node]-max(dp1[nxt],dp2[nxt]));
        }
    }

    dp1[node] = take;

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

    vector <int> dp1(n+1,0),dp2(n+1,0);
    
    dp(1,0,adj,dp1,dp2);

    cout<<max(dp1[1],dp2[1])<<endl;
    return 0;
}