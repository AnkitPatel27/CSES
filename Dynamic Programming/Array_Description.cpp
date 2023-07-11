#include <bits/stdc++.h>
using namespace std;
 
long long dp[100001];
const long long p = 1e9+7;
 
int  main(){
    
    int n,m;
    cin>>n>>m;
    
    vector <long long> x(n);
    
    for(int i =0;i<n;i++){cin>>x[i];}
    for(int i =1;i<=m;i++){dp[i]=1;}
    
    if(x[0]!=0){
        long long ind = x[0];
        for(int j=1;j<=m;j++){
            if(j!=ind){
                dp[j]=0;
            }
        }
    }
    
    for(int i=1;i<n;i++){
        if(x[i]!=0){
            long long ind = x[i];
            if(ind==1){
                if(m>=2){
                    dp[1]+=dp[2];
                    dp[1]%=p;
                }
            }
            else if(ind==m){
                if(m!=1){
                    dp[m]+=dp[m-1];
                    dp[m]%=p;
                }
            }
            else{
                dp[ind]+=dp[ind-1]+dp[ind+1];
                dp[ind]%=p;
            }
            
            for(int j=1;j<=m;j++){
                if(j!=ind){
                    dp[j]=0;
                }
            }
 
        }
        else{
            long long up = dp[1];
            long long temp =up;
            
            if(m>=2){
                dp[1]+=dp[2];
                dp[1]%=p;
            }
            for(int j=2;j<=m-1;j++){
                temp = dp[j];
                dp[j]+=up+dp[j+1];
                dp[j]%=p;
                up = temp;
            }
 
            if(m!=1){
                dp[m]+=up;
                dp[m]%=p;
            }
 
        }
    }
    
    long long ans = 0;
    for(int i =1;i<=m;i++){
        ans+=dp[i];
        ans%=p;
    }
    
    cout<<ans<<endl;
    return 0;
}