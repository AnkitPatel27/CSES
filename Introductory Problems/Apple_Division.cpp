#include <bits/stdc++.h>
using namespace std;
 
long long dp(int i,long long curSum,vector <long long> &p,long long target){
    if(curSum>target) return 0ll;
    if(i>=p.size()) return curSum;
    if(curSum==target){
        // cout<<"ranned : \n";
        return curSum;
    }
    
    long long y = dp(i+1,curSum,p,target);
    long long t = dp(i+1,curSum+p[i],p,target);
    // cout<<"i : "<<i<<"y : "<<y<<"t :"<<t<<endl;
    return max(y,t);
}

int main(){
    int n;
    cin>>n;
    long long sum = 0;
    vector <long long> p(n);
    for(int i = 0; i < n; i++){
        cin>>p[i];
        sum = sum+p[i];
    }
    long long target = sum/2;
    // cout<<"target :"<<target<<endl;
    long long k = dp(0,0,p,target);
    // cout<<k<<" "<<(sum-k)<<endl;
    cout<<(sum-k-k)<<endl;
    return 0;
}