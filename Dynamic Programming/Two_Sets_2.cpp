#include <bits/stdc++.h>
using namespace std;

const long long p = 1e9+7;
vector <vector <int>> mem(501,vector<int>(125251,-1));

long long dp(int i,int n,int sum,int target){
    if(sum==target){
        return 1ll;
    }
    if(i>n){
        return 0ll; 
    }

    if(mem[i][sum]!=-1){
        return mem[i][sum];
    }

    long long ans = dp(i+1,n,sum,target);
    
    if(sum+i<=target){
        ans+=dp(i+1,n,sum+i,target);
        ans%=p; 
    }

    return mem[i][sum] = ans;

} 

int main(){
    int n;
    cin>>n;
    int sum = (n*(n+1))/2;

    if(sum%2==0){
        cout<<(dp(1,n,0,sum/2)*500000004)%p<<endl;
    }
    else{
        cout<<0<<endl;
    }

    return 0;
}