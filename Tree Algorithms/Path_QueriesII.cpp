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
vvi part(N,vi(21,0));

int timer = 1;

void dfs(int node,int par){
    startt[node] = timer++;
    cout<<"node : "<<node<<" : "<<par<<endl;
    part[node][0] = par;
    cout<<part[node][0]<<endl;
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
        cout<<l<<" : "<<r<<" : "<<newVal<<endl;
        lazyNode[index] = 0;
        return;
    }

    if(lazyNode[index]!=0){
        lazyNode[2*index]+= lazyNode[index];
        lazyNode[2*index+1]+= lazyNode[index];
        wst[index]+= lazyNode[index];
        lazyNode[index]=0;
    }

    if(x<=l && r<=y){
        cout<<"Tried\n";
        lazyNode[index] += newVal; 
        return;
    }

    int mid = (l+r)>>1;
    UpdateSeg(2*index,l,mid,x,y,newVal);
    UpdateSeg(2*index+1,mid+1,r,x,y,newVal);
    // wst[index] = max(wst[2*index],wst[2*index+1]);

}

ll querySeg(int index,int l,int r,int x,int y){
    if(y<l || r<x){
        return 0;
    }

    if(l==r){
        cout<<l<<" : "<<r<<endl;
        wst[index] +=  lazyNode[index];
        lazyNode[index] = 0;
        return wst[index];
    }

    if(lazyNode[index]!=0){
        wst[index]+=lazyNode[index];
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
    return max(a,b);

} 

int goUp(int a,int k){
    for (int i = 0; i < 21; i++)
    {
        int res = (1<<i)&k;
        if(res){
            a = part[a][i];
        }
    }
    return a;
}

int findLCA(int a,int b){
    if(startt[b]>startt[a]){
        swap(b,a);
    }

    if(startt[a]<=startt[b] && endt[b]<=endt[a]){
        return a;
    }
    
    for (int i = 20; i >= 0; i--)
    {
        
        if(startt[a]<=startt[b] && endt[b]<=endt[a]){

        }
        else{
            a = part[a][i];
        }
    }
    
    return part[a][0];
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
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

    cout<<"Done\n";
    dfs(1,1);
    cout<<"Done\n";


    for (int i = 1; i < 21; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            part[j][i] = part[part[j][i-1]][i-1];
        }
    }

    for (int i = 1; i <=n; i++)
    {
        cout<<part[i][0]<<" "; 
    }
    cout<<endl;

    cout<<"Done\n";
    
    FOR(1,n,1){
        cout<<startt[i]<<" ";
    }
    cout<<endl;
    FOR(1,n,1){
        cout<<endt[i]<<" ";
    }
    cout<<endl;

    FOR(1,n,1){
        UpdateSeg(1,1,n,startt[i],startt[i],weight[i]);
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
            ll s1,s2;
            cin>>s1>>s2;
            int s = findLCA(s1,s2);
            cout<<"LCA : "<<s<<endl;
            cout<<max(querySeg(1,1,n,startt[s],startt[s1]),querySeg(1,1,n,startt[s],startt[s2]))<<endl;     
        }
    }

    return 0;
}
