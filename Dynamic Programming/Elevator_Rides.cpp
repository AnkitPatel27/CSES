#include <bits/stdc++.h>
using namespace std;
 
int ans = 20;
 
int main(){
    int n,x;
    cin>>n>>x;
    
    //end start
    vector <int> a(n);
    vector <pair<int,int>> dp(1<<n);
    
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    
    dp[0] = {0,0};
    
    for(int i = 1;i<(1<<n);i++){
        dp[i] = {25,0};
        for(int j = 0;j<n;j++){
            if(i&(1<<j)){
                auto cur = dp[i^(1<<j)];
                if(cur.second+a[j]<=x){
                    cur.second = cur.second +a[j];
                }
                else{
                    cur.second = a[j];
                    cur.first++;
                }
                
                dp[i] = min(dp[i],cur);
            }
        }
    }
    
 
      cout << dp[(1 << n) - 1].first + (dp[(1 << n) - 1].second > 0);
 
    return 0;
}