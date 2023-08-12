#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
ll fastPower(ll a,ll b,ll mod){
    if(b==0){
        return 1;
    }
    if(a==0){
        return 0;
    }

    ll result = 1;
    while(b>0){
        if((b&1)){
            result = (result*a)%mod;
        }
        a = (a*a)%mod;
        b=b>>1;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        ll a,b,c;
        cin >>a>>b>>c;

        cout<<fastPower(a,fastPower(b,c,(ll)1e9+6),(ll)1e9+7)<<endl;
    }
    
    return 0;
}