#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
int n,m,k;
vvi adj(1002);
vvi cap(1002,vi(1002,0));
vi parent(1002,-1);
vi vis(1002,-1);

int bfs(){
    fill(parent.begin(),parent.end(),-1);
    int s = 0;
    int t = 1001;
    queue<pair<int,int>> q;
    parent[s] = -2;
    q.push({s,INT_MAX});

    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        // cout<<"cur : "<<cur<<endl;
        q.pop();
        for(int nxt: adj[cur]){
            if(parent[nxt] == -1 && cap[cur][nxt]){
                parent[nxt] = cur;
                int new_flow = min(flow,cap[cur][nxt]);
                if(nxt == t){
                    return new_flow;
                }
                q.push({nxt,new_flow});
            }
        }
    }

    return 0;
    
}

void dfs(int node = 0,int par = -1){
    vis[node] = 1;
    for(int nxt: adj[node]){
        if(vis[node]==1 && nxt!=par && cap[node][nxt]>0){
            dfs(nxt,node);
        }
    }
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cin>>n>>m>>k;

    FOR(1,k,1){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(n+y);
        // cout<<x<<" : "<<n+y<<endl;
        adj[n+y].push_back(x);
        cap[x][n+y]=1;
        // cap[n+y][x]=1;
    }    

    FOR(1,n,1){
        adj[0].push_back(i);
        // cout<<0<<" : "<<i<<endl;
        cap[0][i] = 1;
    }
    FOR(1,m,1){
        adj[n+i].push_back(1001);
        // cout<<n+i<<" : "<<1001<<endl;
        cap[n+i][1001] = 1;
    }

    int ans = 0;
    while(1){
        int flow = bfs();
        if(flow ==0){
            break;
        }
        else{
            // cout<<flow<<endl;
            ans+=flow;
            int cur = 1001;
            while(cur!=0){
                // cout<<cur<<" ";
                int par = parent[cur];
                cap[par][cur]--;
                cap[cur][par]++;
                cur = par;
            }
            // cout<<cur<<endl; 
        }
    }


    // dfs();
    cout<<ans<<"\n";
    // vector <int> vis1(1001,0);

    for(int i =1;i<=n;i++){
        // vi vis1(1001,0);
        fill(vis.begin(),vis.end(),0);
        for(int nxt: adj[i]){
            // cout<<i<<" "<<nxt<<" "<<cap[i][nxt]<<endl;
            if(cap[i][nxt]==0 && vis[nxt]==0){
                cout<<i<<" "<<nxt-n<<"\n";
            }
            vis[nxt] = 1;
        }
    }
    // for (int i = 0; i < 1002; i++)
    // {
    //     if(vis[i]==1){
    //         cout<<i<<endl;
    //         for(int nxt: adj[i]){
    //             cout<<"nxt : "<<nxt<<endl;
    //             if(vis[nxt]==0 && cap[i][nxt]==0){
    //                 if(i>n){
    //                     i = i-n;
    //                 }
    //                 if(nxt>n){
    //                     nxt = nxt-n;
    //                 }
    //                 cout<<i<<" "<<nxt<<endl;
    //             }
    //         }
    //     }
    // }
    

    return 0;
}