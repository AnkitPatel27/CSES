#include <bits/stdc++.h>
using namespace std;
 
long long Minimum_Division(long long x[],long long n,long long Capacity){
    long long ans = 0;
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        ans+=x[i];
        if(ans>Capacity){
            cnt++;
            ans = x[i];
        }
    }
    return cnt+1;
}

int main(){
    long long n, k;
    cin>>n>>k;
    long long x[n],sum=0;
    long long maxVal = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
        sum+=x[i];
        maxVal = max(maxVal,x[i]);
    }

    if(k==1){
        cout<<sum;
        return 0;
    }

    long long r = sum ;
    long long l = maxVal;
    while(l<r){
        // cout<<"l : "<<l<<" r :"<<r<<endl;
        long long mid = (r+l);
        mid = mid>>1;
        long long ans = Minimum_Division(x,n,mid);
        if(ans==k){
            r=mid;
        } 
        else if(ans>k){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }

    // if(l==r){
        cout<<r<<endl;


    return 0;

}