#include <bits/stdc++.h>
using namespace std;
 
 
 
long long dp[1000][1000];
const long long p = 1e9+7;
int main(){
    int n;
    cin>>n;
    
    for(int i =0;i<n;i++){
        for(int j =0 ;j<n;j++){
            char k;
            cin>>k;
            if(k=='.'){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }
    
    if(dp[0][0]==-1 || dp[n-1][n-1]==-1){
        cout<<0;
        return 0;
    }
    
    dp[0][0] = 1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i!=0 || j!=0) && dp[i][j]!=-1){
                if(i!=0 && dp[i-1][j]!=-1){
                    dp[i][j] += dp[i-1][j];
                    dp[i][j]%=p;
                }
                if(j!=0 && dp[i][j-1]!=-1){
                    dp[i][j] += dp[i][j-1];
                    dp[i][j]%=p;
                }
            }
        }
    }
    
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}