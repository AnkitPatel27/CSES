#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
 



int main(){
    int n;
    cin>>n;
    int q;
    cin>>q;

    vvi par(n+1,vi(33,-1));
    
    for (int i = 2; i <=n; i++)
    {
        cin>>par[i][0];
    }
    

    for(int i=1;i<=32;i++){
        // cout<<i<<endl;
        for (int j = 1; j <=n; j++)
        {
            // cout<<j<<" : ";
            if(par[j][i-1] != -1){
                par[j][i] = par[par[j][i-1]][i-1];
            }
            else{
                par[j][i] = -1;
            }
        }
    }

  
    for (int i = 0; i < q; i++)
    {
        int node,k;
        cin>>node>>k;
        // cout<<"k : "<<k<<endl;
        for (int j = 0; j <32; j++)
        {
            int res = k&(1<<j);
            if(res){
                // cout<<node<<" ; "<<j<<endl;
                // cout<<par[node][j]<<endl;
                node = par[node][j];
                if(node==-1){
                    break;
                }
            }
        }
        cout<<node<<"\n";
        
    }
    


    return 0;
}