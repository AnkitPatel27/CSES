#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
int n,m;
vvi adj(500+1);
vvl cap(501,vl(501,0));
vi parent(500+1),vis(500+1);

ll bfs(int s,int t){
    // cout<<"Node \n";
    fill(parent.begin(),parent.end(),-1);
    parent[s] = -2;
    queue<pair<int,ll>> q;
    q.push({s,LONG_LONG_MAX});

    while(!q.empty()){
        int cur = q.front().first;
        ll flow = q.front().second;
        // cout<<cur<<" "<<flow<<endl;
        q.pop();
        for(int next : adj[cur]){
            // cout<<next<<endl;
            if( parent[next]==-1 && cap[cur][next]){
                parent[next] = cur;
                ll newFlow = min(flow,cap[cur][next]);
                if(next == t){
                    return newFlow;
                }
                q.push({next,newFlow});
            }
        }
    }

    return 0;
}

void dfs(int node,int par){
    vis[node] = 1;   
    // cout<<node<<" "<<par<<endl;
    for(int nxt:adj[node]){
        if(nxt!=par && cap[node][nxt]>0 && vis[nxt]==0){
            dfs(nxt,node);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;

    FOR(1,m,1){
        int x,y;
        cin>>x>>y;
        // if(x>y){
        //     swap(x,y);
        // }
        adj[x].push_back(y);
        adj[y].push_back(x);
        cap[x][y] = 1;
        cap[y][x] = 1;
    }

    ll ans = 0; 
    while(1){
        ll netFlow = bfs(1,n);
        ans+=netFlow;
        // cout<<"netFlow : "<<netFlow<<"\n";
        if(netFlow){
            int cur = n;
            while(cur!=1){
                int par1 = parent[cur];
                cap[par1][cur] -= netFlow;
                cap[cur][par1] += netFlow;
                cur = par1;
            }
            
        }
        else{
            break;
        }   
    }

    cout<<ans<<"\n";
    dfs(1,0);
    for (int i = 0; i < n; i++)
    {
        if(vis[i]==1){
            for(int nxt:adj[i]){
                if(cap[i][nxt]==0 && vis[nxt]==0){
                    cout<<i<<" "<<nxt<<"\n";
                }

            }
        }
    }
    
    return 0;
}