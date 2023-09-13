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
vvi adj(501);
vvl cap(501,vl(501,0));
vi parent(501,-1);

ll bfs(int s,int t){
    fill(parent.begin(),parent.end(),-1);
    parent[s]=-2;
    queue<pair<int,ll>>q;
    q.push({s,LONG_LONG_MAX});
    while(!q.empty()){
        int cur = q.front().first;
        ll flow = q.front().second;
        // cout<<"cur : "<<cur<<endl;
        q.pop();
        for(int nxt:adj[cur]){
            // cout<<"nxt : "<<nxt<<endl;
            if(parent[nxt]==-1 && cap[cur][nxt]){
                parent[nxt]=cur;
                ll newFlow = min(flow,cap[cur][nxt]);
                if(nxt==t){
                    return newFlow;
                }
                q.push({nxt,newFlow});
            
            }
        }
    }
    return 0ll;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;

    FOR(1,m,1){
        int x,y;
        ll w ;
        cin>>x>>y>>w;
        
        adj[x].push_back(y);
        adj[y].push_back(x);
        cap[x][y] += w;
    }

    ll ans = 0;
    ll netflow = 0;
    while(1){
        netflow = bfs(1,n);
        // cout<<netflow<<endl;
        ans+=netflow;
        if(netflow){
           int cur1 = n;
            while(cur1!=1){
                int par = parent[cur1];
                cap[par][cur1]-=netflow;
                cap[cur1][par]+=netflow;
                cur1 = par;
            } 
        }
        else{
            break;
        }
    }

    cout<<ans<<endl;

    return 0;
}