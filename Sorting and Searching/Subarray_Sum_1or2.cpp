#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long n;
    cin>>n;
    vector <long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    map<long long,long long> mp;

    long long sum = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        // cout<<"sum : n" <<sum%n << " mp :  "<<mp[(sum%n + n)%n ]<<endl;
        if((sum%n)==0){
            ans++;
        }
        if(mp.find((sum%n + n)%n )!=mp.end()){
            ans+=mp[(sum%n + n)%n ];
        }
        mp[(sum%n + n)%n ]++;
        // cout<<"i : "<<ans<<endl;
    }
    
    cout<<ans<<endl;
    
    return 0;
}