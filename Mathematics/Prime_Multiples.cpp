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
    
    ll n ,k;
    cin>>n>>k;
    vl a(k,0);

    for (int i = 0; i < k; i++)
    {
        cin>>a[i];
        // a[i] = n/a[i];
        
    }

    // for (int i = 0; i < k; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    

    ll ans = 0;
    for (int i = 1; i <(1<<k); i++)
    {
        int cnt = 0;
        ll total = 1; 
        int f = 0;
        for (int j = 0; j < k; j++)
        {
            int res = i&(1<<j);
            if(res){
                cnt++;
                if(total>n/a[j] && f==0){
                    total = n+1;
                    f=1;
                    // break;
                }
                else{
                    total *= a[j];
                }
            }
        }
        if(f==1){
            continue;
        }
        if(cnt%2==0){
            // cout<<i<<" - "<<n/total<<endl;
            ans -= n/total;
        }
        else{
            // cout<<i<<j<<" + "<<total<<endl;
            // cout<<i<<" + "<<n/total<<endl;
            ans+=n/total;
        }
        
        /* code */
    }
    
    cout<<ans;


    return 0;
}