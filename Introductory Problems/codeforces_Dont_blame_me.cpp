#include <bits/stdc++.h>
using namespace std;

int check_bits(int k){
    int count =0;
    for (int i = 0; i < 6; i++)
    {
        if((k>>i)&1){
            count++;
        }
    }
    return count;
}
int p = 1e9+7;
int dp(int i,int curSum,int k,vector <int> &a,vector <vector <int>> &memo){
    if(i==a.size()){
        // cout<<" curSum : "<<curSum<<endl;
        if(curSum!=-1 && check_bits(curSum)==k){
            return 1;
        }
        return 0;
    }
    if(check_bits(curSum)<k){
        return 0;
    }
    if(memo[i][curSum]>0){
        return memo[i][curSum];
    }
    long long ans = 0;
    ans += dp(i+1,curSum,k,a,memo);
    if(curSum==-1){
        ans = (ans+ (long long)dp(i+1,a[i],k,a,memo))%p;
    }
    else{
        ans = (ans+ (long long)dp(i+1,curSum&a[i],k,a,memo))%p;
    }
    if(curSum!=-1){
        return memo[i][curSum] = (int)ans; 
    }
    return (int)ans;
}   

int main(){
    // cout<<check_bits(3)<<endl;
    int test,cases=0;
    cin>>test;
    while(test){
        test--;
        cases++;
        int n,k;
        cin>>n>>k;
        vector <int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        vector <vector <int>>memo(200009,vector <int> (64,-1));
        int ans = dp(0,-1,k,a,memo);
        cout<<ans<<endl;
    }
    return 0;
}