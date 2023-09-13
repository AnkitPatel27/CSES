#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
ll fastPower(ll a,ll b){
    if(a==0){
        return 0ll;
    }
    
    if(b==0){
        return 1;
    }

    ll res = 1;
    ll mod = (ll)1e9+7ll;
    while(b>0){
        if(b%2==1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b/=2;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    //n+m-1Cn-1

    vl invert((int)2e6+10,1),mult((int)2e6+2,1);
    ll mod = (ll)(1e9) + 7ll;

    FOR(1,(int)2e6+3,1){
        mult[i] = (mult[i-1]*i)%mod;
    }

    FOR(2,(int)2e6+3,1){
        invert[i] = (invert[i-1]*fastPower(i,mod-2ll))%mod;
    }
    // cout<<invert[2]<<" "<<invert[3]<<endl;

    ll ans = (mult[n+m-1]*invert[n-1])%mod;
    ans = (ans*invert[m])%mod;

    cout<<ans<<endl;

    return 0;
}