#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
vl freq(27,0);
vl invert((int)1e6+10,1);
ll mod = (ll)(1e9) + 7ll;

ll pow1(ll a,ll b){
    if(b == 0){
        return 1;
    }
    if(a==0){
        return 0;
    }

    ll res = 1;
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
    
    string s;
    cin>>s;



    ll total = 1;

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]-'a']++;
    }
    

    // freq[s[0]-'1']++;
    FOR(1,s.length(),1){
    //    freq[s[i]-'a']++;
       total  = (total*i)%mod;      
    }

    FOR(2,s.length()+1,1){
        invert[i] = (invert[i-1]*pow1(i,mod-2))%mod;
        // cout<<invert[i]<<"\n";
    }


    

    for (int i = 0; i < 27; i++)
    {
        // if(freq[s[i]-'a']!=0){
        // cout<<freq[i]<<" : ";
        total = (total*invert[freq[i]])%mod;
        // }
    }
    // cout<<"\n";

    cout<<total<<"\n";

    return 0;
}