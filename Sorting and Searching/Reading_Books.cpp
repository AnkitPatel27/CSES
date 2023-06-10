#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long n;
    cin>>n;
    vector <long long> time(n);
    for (long long i = 0; i < n; i++)
    {
        cin>>time[i];
    }
 
 
    if(time.size()==1){
        cout<<2*(*time.begin())<<endl;
        return 0;
    }
    sort(time.begin(),time.end());
    long long first = time[n-1];
    long long ans = time[n-1];
    long long last = time[n-1];
    long long l = n-2;
 
    while(l>=0){
        long long k = 0;
        // cout<<"last : "<<last<<" size : "<<l<<endl;
        auto temp = last;
        while(l>=0 && k<=temp){
            k+=time[l];
            l--;
        }
        if(l>=0){
            l++;
            k-=time[l];
        }
        ans+=k;
        last=k;
    }
    // cout<<"last : "<<last<<" ans : "<<ans<<endl;
    if(ans-first>=first){
        long long c = max(first-((ans-last)-(ans-first)),last);
        ans = ans -last;
        ans = ans + c;
    }
    else{
        ans = ans-last;
        ans = ans + first;
    }
    cout<<ans<<endl;
    return 0;
}