#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)

ll fastpower(ll a,ll b){
      if(b==0){
        return 1;
    }
    if(a==0){
        return 0;
    }

    ll mod = (ll)1e9+7;
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

ll gp(ll a,ll n){
    ll mod = (ll)1e9+7;
    ll ans = (fastpower(a,n+1)-1+mod)%mod;
    ans = (ans*fastpower(a-1,mod-2ll))%mod;
    // cout<<"ans : "<<ans<<endl;
    // cout<<a<<n<<endl;
    return ans;
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vvl num(n,vl(2,0));

    ll powMod = (ll)1e9+6;
    ll mod = (ll)1e9+7;

    ll mult = 1;
    ll number = 1;
    // ll numd = 1;
    // ll a = 1;
    ll divnum = 1;
    ll sumMult = 1;
    for (int i = 0; i < n; i++)
    {
        cin>>num[i][0]>>num[i][1];
        number = (number*(num[i][1]+1ll))%mod;
        divnum = (divnum*fastpower(num[i][0],num[i][1]))%mod;
        // numd = (numd*(num[i][1]+1))%powMod;

        // a = (a*(fastpower(num[i][0],num[i][1])))%mod;
        sumMult = (sumMult*gp(num[i][0],num[i][1]))%mod;
    }
    
    // ll multdiv =fastpower(a,numd);
    int f = -1;
    ll numd = 1;
    for (int i = 0; i < n; i++)
    {
        if((num[i][1]+1)%2==0){
            f = i;
            numd = (numd*((num[i][1]+1ll)/2))%powMod;
            break;
        }
    }

    ll ans = 1;
    
    if(f!=-1){
        for (int i = 0; i < n; i++)
        {
            if(i!=f){
                numd = (numd*(num[i][1]+1))%powMod;
            }
        }
        ans = (ans * fastpower(divnum,numd))%mod;
    }
    else{
        divnum = 1;
        numd = 1;
        for (int i = 0; i < n; i++)
        {
            divnum = (divnum*fastpower(num[i][0],num[i][1]/2))%mod;
            numd = (numd*(num[i][1]+1))%powMod;
        }
        ans = (ans * fastpower(divnum,numd))%mod;
    }
    
    

    cout<<number<<" ";
    cout<<sumMult<<" ";
    cout<<ans;

    return 0;
}