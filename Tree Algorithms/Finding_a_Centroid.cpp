#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vvp vector<vector<pair<int,int>>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
int distDfs(int node,int par,vvp &adj,vi &dist,int n){

    int ans = 1;
    for(auto p:adj[node]){
        int nxt = p.first;
        int ind = p.second;
        if(nxt!=par){
            int k =distDfs(nxt,node,adj,dist,n);
            dist[ind]=k;
            ans+=k;
        }
    }

    return ans;

}


int dfs(int node,int par,vvp &adj,vi &dist,int n){
    int maxNode =n/2;
    int f = 1;
    int i = 0;
    int k = -1;
    int sum = 0;
    for(auto p:adj[node]){
        int nxt = p.first;
        int ind = p.second;
        if(nxt!=par){
            sum+=dist[ind];
            if(dist[ind]>maxNode){
                f = 0;
                break;
            }
        }
        if(nxt==par){
            k = i;
        }
        i++;
    }

    if(k!=-1){
        if(n-sum-1>maxNode){
            f=0;
        }
    }

    if(f==1){
        return node;
    }

    for(auto p:adj[node]){
        int nxt = p.first;
        int ind = p.second;
        if(nxt!=par){
            int res = dfs(nxt,node,adj,dist,n);
            if(res!=-1){
                return k;
            }
        }
    }

    return -1;
}


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n;
    cin>>n;

    vvp adj(n+1);
    vi dist(2*(n+1),-1);

    int cnt = 0;
    FOR(1,n-1,1){
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,cnt});
        // cout<<cnt<<endl;
        cnt++;
        adj[y].push_back({x,cnt});
        // cout<<cnt<<endl;
        cnt++;
    }




    int k = distDfs(1,1,adj,dist,n);
    int ans = dfs(1,1,adj,dist,n);
    cout<<ans<<endl;
    // for (int i = 0; i < cnt; i++)
    // {
    //     cout<<dist[i]<<" ";
    // }
    
    return 0;
}