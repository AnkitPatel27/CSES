#include <bits/stdc++.h>
using namespace std;
 
 
 
int dp[1000001];
 
int main(){
    int n;
    cin>>n;
    
    dp[0] = 0;
    
    for(int i=1;i<=n;i++){
        int k = i;
        int ans = INT_MAX;
        while(k!=0){
            int num = k%10;
            if(i-num>=0 && num!=0){
                ans=min(ans,1+dp[i-num]);
            }
            k=k/10;
        }
        dp[i] = ans;
    }
    
    cout<<dp[n]<<endl;
    return 0;
}