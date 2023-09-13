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
vvi adj(501),adj1(501);
vvi cap(501,vi(501,0));
vi parent(501,-1);
int len = 0;

int bfs(){
    int s = 1;
    int t = n;
    parent[s]=-2;
    fill(parent.begin(),parent.end(),-1);
    queue<pair<int,int>> q;
    parent[s] =-2;
    q.push({s,INT_MAX});

    while(!q.empty()){
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        len++;
        for(auto x:adj[cur]){
            if(cap[cur][x]>0 && parent[x]==-1){
                parent[x]=cur;
                int newFlow = min(flow,cap[cur][x]);
                if(x==t){
                    return newFlow;
                }
                q.push({x,newFlow});
            
            }
        }
    }

    return 0;
}

void dfs(int node,int par,vi &vis,vi &path){
    // cout<<node<<" ";
    path.push_back(node);
    vis[node]=1;
    for(int nxt:adj1[node]){
        if(vis[nxt]==0 && nxt!=par && cap[node][nxt]==0){
            dfs(nxt,node,vis,path);
            cap[node][nxt] = 1;
            break;
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
        adj[x].push_back(y);
        adj1[x].push_back(y);
        adj[y].push_back(x);
        cap[x][y]=1;
    }

    int k =1;
    int ans =0;
    while(1){
        int flow = bfs();
        ans+=flow;
        if(flow==0){
            break;
        }
        // cout<<len<<endl;
        len = 0;
        int cur = n;
        
        while(cur!=1){
            // cout<<cur<<" ";
            int par = parent[cur];
            // path[cur]=k;
            // if(path[par]!=-1){
                
            // }
            cap[par][cur]-=flow;
            cap[cur][par]+=flow;
            cur=par;
        }
        // cout<<cur<<endl;
        k++;
    }

 
    cout<<ans<<endl;

    for(int i=0;i<ans;i++){
        vi vis(501,0);
        vi path;
        dfs(1,-1,vis,path);
        cout<<path.size()<<"\n";
        for(int a : path){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;
}