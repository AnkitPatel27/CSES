#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector <vector <long long>> dist(n+1,vector <long long> (n+1,-1));

    for (int i = 0; i < m; i++)
    {
        int a,b;
        long long c;
        cin>>a>>b;
        cin>>c;
        if(dist[a][b]==-1){
            dist[a][b] = c;
            dist[b][a] = c;
        }
        else{
            dist[a][b] = min(dist[a][b],c);
            dist[b][a] = dist[a][b];
        }
    }

    for (int i = 1; i <=n ; i++)
    {
        dist[i][i] = 0;
    }
    

    // cout<<"Cal Done";
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(dist[i][k]!=-1ll && dist[k][j]!=-1ll){
                    if(dist[i][j]==-1ll){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                    else if(dist[i][j]>(dist[i][k]+dist[k][j])){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
                
            }
            
        }
        
    }
    for (int i = 0; i < q; i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<dist[a][b]<<"\n";
    }
    

    return 0;
}