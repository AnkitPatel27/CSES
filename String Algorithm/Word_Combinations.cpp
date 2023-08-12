#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vs vector<string>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
vvi match(5000);
vl dp(5000,-1);
ll p = (ll)1e9+7;

ll DP(int i,string &s,vs &k,int &n){
    // cout<<" i "<<i<<endl;
    if(i==n){
        return 1;
    }

    if(dp[i]!=-1){
        return dp[i];
    }

    ll ans = 0;
    for (int j = 0; j < match[i].size(); j++)
    {
        // cout<<" string "<<k[match[i][j]]<<endl;
        ans+=DP(i+(int)k[match[i][j]].size(),s,k,n);
        ans%=p;
    }
    ans%=p;
    dp[i] = ans;
    return dp[i];
    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;

    int n;
    cin>>n;
    
    vs k(n);

    FOR(0,n-1,1){
        cin>>k[i];
    }
    
    FOR(0,n-1,1){
        // cout<<k[i]<<" ";
        size_t pos = s.find(k[i], 0);
 
        if (pos == string::npos){
            continue;
        }
            // cout << "NONE";
    
        while (pos != string::npos) {
            // cout<<pos<<" ";
            match[pos].push_back(i);
            pos = s.find(k[i], pos + 1);
        }
        // cout<<endl;
    }

    int ssize = s.size();
    ll ans = DP(0,s,k,ssize);
    cout<<ans<<endl;


    return 0;
}