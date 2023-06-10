#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long n, k;
    cin>>n>>k;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    long long l=0,r=0;
    long long ans=0,c=0;
    map<long long,long long>cur;

    while (l<n)
    {
        while(r<n && c+(cur[arr[r]]==0)<=k){
            c+=(cur[arr[r]]==0);
            cur[arr[r]]++;
            r++;
        }
        // cout<<"r : "<<r<<" l : "<<l<<endl;
        ans+=r-l;
        c-=(cur[arr[l]]==1);
        cur[arr[l]]--;
        l++;
    }
    cout<<ans<<endl;
    return 0;
}