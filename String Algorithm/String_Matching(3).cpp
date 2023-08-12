#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s,p;
    cin>>s>>p;

    int n = s.size();
    int m = p.size();

    string ns;

    ns = p+":"+s;

    ll l=0,r=0;
    int k = ns.size();
    // cout<<ns<<endl;
    vl z(k,0);
    for (int i = 1; i < k; i++)
    {
        if(i<r){
            z[i] = min(z[i-l],(ll)(r-i));
        }
        while(i+z[i]<k && ns[i+z[i]]==ns[z[i]]){
            z[i]++;
        }
        if(i+z[i]>r){
            l = i;
            r = i + z[i];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        if(z[i]==m){
            ans++;
        }
    }
    
    cout<<ans<<endl;

    return 0;
}