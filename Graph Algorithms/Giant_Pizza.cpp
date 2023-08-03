#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>

void addEdge(int a,int b,int na,int nb,vvi &adj,vvi &radj){
    a = 2*a^na;
    b = 2*b^nb;
    int nega = a^1;
    int negb = b^1;
    adj[nega].push_back(b);
    adj[negb].push_back(a);
    // cout<<"edge "<<nega<<" -> "<<b<<endl;
    // cout<<"edge "<<negb<<" -> "<<a<<endl;
    radj[a].push_back(negb);
    radj[b].push_back(nega);
}


void dfs(int node,vvi &adj,vi &vis,vi &order){
    if(vis[node]){
        return;
    }
    // cout<<node<<"\n";
    vis[node] = 1;
    for(int nxt : adj[node]){
        dfs(nxt,adj,vis,order);
    }
    order.push_back(node);
}

void dfs2(int node,vvi &adj,vi &vis,int comp){
    if(vis[node]){
        return;
    }
    // cout<<node<<"\n";
    vis[node] = comp;
    for(int nxt : adj[node]){
        dfs2(nxt,adj,vis,comp);
    }
}

int main(){
    int n;
    int m;
    cin>>n;
    cin>>m;

    vvi adj(2*(m+1)),radj(2*(m+1));

    for (int i = 0; i < n; i++)
    {
        char k1,k2;
        int n1,n2;
        cin>>k1>>n1>>k2>>n2;
        int k11=0,k22=0;
        if(k1=='-'){
            k11=1;
        }
        if(k2=='-'){
            k22=1;
        }

        addEdge(n1,n2,k11,k22,adj,radj);
    }
    
    vi order,vis(2*m+2,0),rvis(2*m+2,0);
    for (int i = 2; i <=2*m+1; i++)
    {
        if(vis[i]==0){
            // cout<<"dfs : "<<i<<endl;
            dfs(i,adj,vis,order);
        }
    }


    
    reverse(order.begin(),order.end());
    int comp = 1;
    for(int u:order){
        if(rvis[u]==0){
            // cout<<"rdfs : "<<u<<endl;
            dfs2(u,radj,rvis,comp);
            comp++;
        }
    }


    vi assign(m+1);
    for (int i = 1; i <=m ; i++)
    {
        int p = 2*i;
        int negp = p+1;
        // cout<<"sort : "<<p<<endl;
        // cout<<rvis[p]<<" "<<rvis[negp]<<endl;
        if(rvis[p]==rvis[negp]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        } 
        assign[i] = rvis[p]>rvis[negp];
    }
        
    for (int i = 1; i <=m; i++)
    {
        if(assign[i]){
            cout<<"+ ";
        }
        else{
            cout<<"- ";
        }
    }
    
    return 0;
}

