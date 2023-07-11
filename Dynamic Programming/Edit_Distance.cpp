#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n,m;
    n = s1.size();
    m = s2.size();
    // cout<<n<<m<<endl;
    vector <vector  <int>> dp(5001,vector<int>(5001));
    
    dp[0][0]=0;
    for(int i =1;i<=n;i++){
        dp[i][0] = i;
    }
    
    
    for(int i =1;i<=m;i++){
        dp[0][i] = i;
    }
    
    
    for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1);
                dp[i][j] = min(dp[i][j],1+dp[i-1][j-1]);
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    
    cout<<dp[n][m];
    
    return 0;
}