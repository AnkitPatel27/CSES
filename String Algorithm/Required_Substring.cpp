#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
string pat;
int n ,m;
vvl DP(1001,vl(101,-1));
vl pi(1001,0);
ll mod = (ll)1e9+7;

void lps(){
    pi[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while(j>0 && pat[j]!=pat[i]){
            j = pi[j-1];
        }
        if(pat[i]==pat[j]){
            j++;
        }
        pi[i]=j;
    }
    
}

ll dp(int i,int j){
    // cout<<i<<" : "<<j<<endl;

    if(DP[i][j]!=-1){
        return DP[i][j];
    }


    if(i==n){
        if(j==m){
            return 1ll;
        }
        else{
            return 0ll;
        }
    }

    if(j==m){
        return (26ll*dp(i+1,j))%mod;
    }

    ll ans = 0;
    for (char A = 'A'; A <='Z' ; A++)
    {
        int t = j;
        while(true){
            if(pat[t]==A){
                t++;
                break;
            }
            else if(t){
                t = pi[t-1];
            }
            else{
                break;
            }
        }
        ans+=dp(i+1,t);
        ans%=mod;

    }
    DP[i][j] = (ans%mod);
    return DP[i][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>pat;
    // n = (int)s.size();

    m = (int)pat.size();
    lps();
    cout<<dp(0,0)<<endl;


    return 0;
}