#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n]={0};
    int ind[n+1]={0};
    int val[n+1]={0};
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        ind[arr[i]] = i+1;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if(ind[i]<ind[i-1]){
            ans+=1;
            val[i-1] = 1;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        int inda = arr[a-1];
        int indb = arr[b-1];
        int indaval = b;
        int indbval = a;
        ind[inda] = indaval;
        ind[indb] = indbval;
        swap(arr[a-1],arr[b-1]);
        // cout<<inda<<" : "<<indb<<endl;
        if(inda>0){
            ans -=  val[inda-1];
            if(ind[inda-1]>ind[inda]){
                val[inda-1]=1;
                ans++;
            }
            else{
                val[inda-1]=0;
            }
            // cout<<"a less :"<<ans<<endl;
        }
        if(indb>0){
            ans -=  val[indb-1];
            if(ind[indb-1]>ind[indb]){
                ans++;
                val[indb-1]=1;
            }
            else{
                val[indb-1]=0;
            }
            // cout<<"b less :"<<ans<<endl;
        }
        if(inda<n){
            ans -=  val[inda];
            if(ind[inda]>ind[inda+1]){
                val[inda]=1;
                ans++;
            }
            else{
                val[inda]=0;
            }
            // cout<<"a more :"<<ans<<endl;
        }
        if(indb<n){
            ans -=  val[indb];
            if(ind[indb]>ind[indb+1]){
                val[indb]=1;
                ans++;
            }
            else{
                val[indb]=0;
            }
            // cout<<"b more :"<<ans<<endl;
        }
        

        cout<<ans<<endl;
    }
    
    return 0;
}