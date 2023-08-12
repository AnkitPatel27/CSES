#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
ll mod = (int)1e9+9;
ll pow1 = 9973;

vl roll_hash(string s){
    int n = s.size();
    vl rhash(n,0);
    ll curhash = 0;

    for (int i = 0; i < n; i++)
    {
        if(i!=0){
            rhash[i] = (rhash[i-1]*pow1)%mod;
        }
        rhash[i] = (rhash[i]+(ll)(s[i]-'a'))%mod;
    }
    
    return rhash;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s,pattern;
    cin>>s>>pattern;

    vl shash = roll_hash(s);
    vl phash = roll_hash(pattern);

    

    int n,m;
    n = s.size();
    m = pattern.size();

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<shash[i]<<" ";   
    // }
    // cout<<endl;
    

    ll p_pow = 1;
    int ans = 0;



    for (int i = 0; i < m; i++)
    {
        p_pow = (p_pow * pow1)%mod;
    }

    for (int i = 0; i+m-1 < n; i++)
    {
        ll rhash = shash[i+m-1];
        ll lhash = (i==0)?0:((shash[i-1]*p_pow)%mod);
        ll curhash = (rhash-lhash+mod)%mod;
        if(curhash==phash[m-1]){
            ans++;
        }
    }

    cout<<ans;
    

    return 0;
}