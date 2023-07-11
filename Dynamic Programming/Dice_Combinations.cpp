
#include <bits/stdc++.h>
using namespace std;
 
long long mem[1000000+9]={0};
long long p = 1e9+7;
 
 
long long dp(int n){
    if(n==1 || n==0){
        return 1;
    }
    
    if(mem[n]>0){
        return mem[n];
    }
    
    long long ans = 0;
    for(int i =1;i<=6;i++){
        if(i<=n){
            ans = ((ans%p) + (dp(n-i)%p))%p;
        }
        else{
            break;
        }
    }
    return mem[n]=(ans%p);
}
 
int main()
{
    int n;
    cin>>n;
    long long ans = dp(n);
    cout<<ans<<endl;
    return 0;
}