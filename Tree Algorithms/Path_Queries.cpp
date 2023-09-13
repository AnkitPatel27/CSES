#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
int n;
int N = (int)2e5+1;
vvi adj(N);
vl weight(N,0),wst(4*N ,0),lazyNode(4*N,0);
vi startt(N,0),endt(N,0);

int timer = 1;

void dfs(int node,int par){
    startt[node] = timer++;
    for(int nxt:adj[node]){
        if(nxt!=par){
            dfs(nxt,node);
        }
    }

    endt[node] = timer-1;
}

void UpdateSeg(int index,int l ,int r,int x,int y,ll newVal){
    if(y<l || r<x){
        return ;
    }

    if(l==r){
        wst[index] += newVal + lazyNode[index];
        lazyNode[index] = 0;
        return;
    }

    if(lazyNode[index]!=0){
        lazyNode[2*index]+= lazyNode[index];
        lazyNode[2*index+1]+= lazyNode[index];
        wst[index]+=lazyNode[index]*(r-l+1);
        lazyNode[index]=0;
    }

    if(x<=l && r<=y){
        lazyNode[index] += newVal; 
        return;
    }

    int mid = (l+r)>>1;
    UpdateSeg(2*index,l,mid,x,y,newVal);
    UpdateSeg(2*index+1,mid+1,r,x,y,newVal);


}

ll querySeg(int index,int l,int r,int x,int y){
    if(y<l || r<x){
        return 0;
    }

    if(l==r){
        // cout<<l<<" : "<<r<<endl;
        wst[index] +=  lazyNode[index]*(r-l+1);
        lazyNode[index] = 0;
        return wst[index];
    }

    if(lazyNode[index]!=0){
        wst[index]+=lazyNode[index]*(r-l+1);
        lazyNode[2*index]+= lazyNode[index];
        lazyNode[2*index+1]+= lazyNode[index];
        lazyNode[index]=0;
    }

    if(x<=l && r<=y){
        return wst[index];
    }

    int mid = (l+r)>>1;
    ll a =querySeg(2*index,l,mid,x,y);
    ll b =querySeg(2*index+1,mid+1,r,x,y);
    return a+b;

} 



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin>>n>>q;

    FOR(1,n,1){
        cin>>weight[i];
    }

    FOR(1,n-1,1){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,1);

    // FOR(1,n,1){
    //     cout<<startt[i]<<" ";
    // }
    // cout<<endl;
    // FOR(1,n,1){
    //     cout<<endt[i]<<" ";
    // }
    // cout<<endl;

    FOR(1,q,1){
        UpdateSeg(1,1,n,startt[i],endt[i],weight[i]);
    }

    FOR(1,q,1){
        int q1;
        cin>>q1;
        if(q1==1){
            ll s,x;
            cin>>s>>x;
            UpdateSeg(1,1,n,startt[s],endt[s],x-weight[s]);
            weight[s] = x;
        }
        else{
            ll s;
            cin>>s;
            cout<<querySeg(1,1,n,startt[s],startt[s])<<endl;
        }
    }

    return 0;
}
