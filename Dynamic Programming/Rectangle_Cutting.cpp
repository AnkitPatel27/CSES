#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0<<endl;
        return 0;
    }
    vector <vector <int>> dp(a+1, vector <int>(b+1));
    
    for(int i=1;i<=a;i++){
        dp[i][1] = i-1;
    }
    
    for(int i=1;i<=b;i++){
        dp[1][i] = i-1;
    }
    // cout<<"ye"<<endl;
    for(int i =2;i<=a;i++){
        for(int j =2;j<=b;j++){
            if(i==j){
                dp[i][j]=0;
            }
            else{
                int ans = INT_MAX;
                // cout<<"i : "<<i<<" j : "<<j<<endl;
                for(int k=1;k<=((i+1)/2);k++){
                    // cout<<"k : "<<k<<endl;
                    ans = min(ans,1+dp[k][j]+dp[i-k][j]);
                }
                
                for(int k=1;k<=((j+1)/2);k++){
                    ans = min(ans,1+dp[i][k]+dp[i][j-k]);
                }
                // cout<<ans<<" ";
                dp[i][j]=ans;
            }
        }
        // cout<<endl;x`
    }
    
    cout<<dp[a][b]<<endl;
    return 0;
}