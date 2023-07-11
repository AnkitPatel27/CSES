#include <bits/stdc++.h>
using namespace std;
 
int dp[100001];
 
int  main(){
    
    int n,x;
    cin>>n>>x;
    
    vector <int> price(n),pages(n);
    
    for(int i =0;i<n;i++){cin>>price[i];}
    for(int i =0;i<n;i++){cin>>pages[i];}
    for(int i =0;i<=x;i++){dp[i]=0;}
    
    
    for(int i=0;i<n;i++){
        for(int j=x;j>=0;j--){
            if(j-price[i]>=0){
                dp[j]=max(dp[j-price[i]]+pages[i],dp[j]);
                // cout<<"i: "<<i<<" price : "<<j<<" : "<<dp[j]<<endl;
            }
        }
        // dp[i] = ans;
    }
    
    cout<<dp[x]<<endl;
    
    return 0;
}