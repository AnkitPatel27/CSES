#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
ll mod = (ll)(1e9) + 7ll;
vl dp(int(1e6)+1,1);
vl invert1(int(1e6)+1,1);

ll pow1(ll a,ll b){
    if(b==0){
        return 1;
    }
    if(a==0){
        return 1;
    }

    ll res = 1;
    while(b!=0){
        if(b%2==1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b/=2;
    }

    return res;
}

ll BinomialCoeff(ll n,ll t){
    if(t>n){
        return 0;
    }
    ll res = 1;
    res = (res*dp[n])%mod;
    res = (res*invert1[t])%mod;
    res = (res*invert1[n-t])%mod;
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    dp[0] =1;
    for (ll i = 1; i <  dp.size(); i++)
    {
        dp[i] = (dp[i-1]*i)%mod;
        // cout<<"i : "<<dp[i]<<"\n";
    }
    
    // cout<<pow1(2,5)<<endl;
    // cout<<pow1(3,5)<<endl;
    invert1[0] = 1;
    invert1[1] = 1;
    for (ll i = 2; i < invert1.size(); i++)
    {
        invert1[i] = (invert1[i-1]*pow1(i,mod-2))%mod;
        // cout<<"invert : "<<invert1[i]<<"\n";
    }

    FOR(1,n,1){
        ll a,b;
        cin>>a>>b;
        cout<<BinomialCoeff(a,b)<<"\n";
    }


    return 0;
}