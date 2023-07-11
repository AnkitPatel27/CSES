#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int n,x;
    cin>>n>>x;
    
    int a[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int dp[x+1];
    for(int i=0;i<x+1;i++){
        dp[i] = 1000009;
    }
    
    sort(a,a+n);
        
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    dp[0] = 0;
    for(int i = 0;i<n;i++){
        for(int j=0;j<=x;j++){
            if(j-a[i]>=0){
                
                dp[j] = min(dp[j],dp[j - a[i]]+1);
            }
            // cout<<j<<a[i]<<" : "<<dp[j]<<" ";
        }
        // cout<<endl;
    }
    
    int ans = dp[x];
    if(ans<1000009){
        cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}