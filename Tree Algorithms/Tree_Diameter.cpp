#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
 
int dia = 0;

int diameter(int node,int par,vvi &adj){
    int max1 = 0;
    int max2 = 0;

    for(int nxt:adj[node]){
        if(nxt!=par){
            int ans = diameter(nxt,node,adj);
            if(ans>max1){
                max2 = max1;
                max1 = ans;
            }
            else if(ans>max2){
                max2 = ans;
            }
        }
    }
    dia = max(dia,max1+max2);
    return max1+1;
}

int main(){
    int n;
    cin>>n;

    vvi adj(n+1);

    for (int i = 1; i <= n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    int l = diameter(1,0,adj);
    cout<<dia<<endl;
    return 0;
}