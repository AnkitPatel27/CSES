#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
ll sumAB(ll a,ll b){
    // a>b
    ll mod = (ll)1e9+7;
    if(a==0){
        return (((b%mod)*((b+1)%mod))/2ll)%mod;
    }

    ll k = (((b%mod)*((b+1)%mod))/2ll)%mod;
    ll p = (((a%mod)*((a-1)%mod))/2ll)%mod;

    return (k-p+mod)%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;

    ll mod = (ll)1e9+7;
    ll ans = 0;

    ll at = 1;
    while(at<=n){
        ll amt = n/at;
        ll last = n/amt;
        // cout<<sumAB(at,last)<<endl;
        ans+=(sumAB(at,last)*(amt%mod));
        ans%=mod;
        at = last+1;
    }
    cout<<ans<<endl;
    return 0;
}  