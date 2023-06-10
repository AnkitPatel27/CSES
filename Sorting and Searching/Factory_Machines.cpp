#include <bits/stdc++.h>
using namespace std;
 
long long manufactured(long long k[],long long n,long long time,long long t){

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum+=(time/k[i]);
        if(sum>t){
            return sum;
        }
    }
    return sum;
    
}

int main(){
    long long n,t;
    cin>>n>>t;
    long long k[n];
    long long maxTime = 0; 
    for (long long i = 0; i < n; i++)
    {
        cin>>k[i];
        maxTime = max(maxTime,k[i]);
    }
    maxTime = (maxTime*t);
    long long l = 1;
    long long r = maxTime;
    while(l<r){
        long long mid = (l+r);
        mid = mid>>1;
        long long produced = manufactured(k,n,mid,t);
        // cout<<l<<" :  "<<r<<" prod : "<<produced<<"TIme : "<<mid<<endl;
        if(produced==t){
            r=mid;
        }
        else if(produced>t){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    cout<<r<<endl;
    return 0;
}