#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long n,a,b;
    cin>>n>>a>>b;

    vector<long long> x(n+1);
    x[0]=0ll;
    for (int i = 1; i <= n; i++)
    {
        cin>>x[i];
        x[i]+=x[i-1];
    }
    
    // for (int i = 0; i <= n; i++)
    // {
    //     cout<<x[i]<<" ";
    // }
    // cout<<endl;

    multiset <long long> s;
    long long ans = -1*1e18;
    for (long long i = a; i <= n; ++i){
        if(i>b){
            s.erase(s.find(x[i-b-1]));
        }
        s.insert(x[i-a]);
        ans=max(ans,x[i]-(*s.begin()));
        // cout<<"ans : "<<ans<<endl;
    }
    cout<<ans<<endl;

    return 0;
}
