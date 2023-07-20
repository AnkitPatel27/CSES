#include <bits/stdc++.h>
using namespace std;

int secondk = -1;

int dfs(int i,vector <vector <int>> &adj,vector <int> &vis,vector <int> &pass,int par){
    if(vis[i]!=-1 && vis[i]!=par){
        // cout<<i<<" : "<<par<<endl;
        secondk = par;
        return i;
    }

    if(pass[i]==1){
        return -1;
    }

    pass[i] = 1;
    vis[i] = par;
    for(auto j : adj[i]){
        int k = dfs(j,adj,vis,pass,i);
        if(k!=-1){
            return k;
        } 
    }
    vis[i] = -1;
    return -1;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector <vector <int>> adj(n+1);

    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    
    vector <int> vis(n+1,-1);
    vector <int> pass(n+1,-1);

    for (int i = 1; i <=n; i++)
    {
        if(pass[i]==-1){
            int k = dfs(i,adj,vis,pass,i);
            if(k!=-1){
                int temp = secondk;
                vector <int>  ans;
                while(secondk!=k){
                    ans.push_back(secondk);
                    secondk = vis[secondk];
                }
                ans.push_back(k);
                ans.push_back(temp);
                cout<<ans.size()<<"\n";
                for (int i = ans.size() - 1; i >= 0; i--)
                {
                    cout<<ans[i]<<" ";
                }
                return 0;
                
            }
        }
    }
    
    cout<<"IMPOSSIBLE";

    return 0;
}