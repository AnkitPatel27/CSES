#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
const long long p =1e9 + 7;
long long dp[1000001] ;
 
int main()
{
    fast_io;
    int n,x;    
    cin>>n;
    cin>>x;
    
    vector<int> a(n);
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	
    dp[0] = 1;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= x; j++){
            if(j-a[i]>=0){
                dp[j]+=dp[j-a[i]];
                dp[j]%=p;
            }
        }
    }
    
    cout<<dp[x];
    return 0;
}