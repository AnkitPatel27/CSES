#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
 
long long FindNum(int n ,long long k){
    // cout<<n<<k<<endl;
    if(n==1){
        return n;
    }
    if(k<=(n/2ll)){
        return 2ll*k;
    }

    if(n%2==0){
        long long ans = FindNum(n/2,k - (n/2));
        return 2ll*ans-1ll;
    }
    else{
        long long ans = FindNum((n+1)/2,k - ((n-1)/2));
        ans--;
        if(ans==0){
            ans = (n+1)/2;
        }
        return 2ll*ans-1ll;
    }
}

int main(){
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        long long x;
        long long y;
        cin>>x>>y;
        cout<<FindNum(x,y)<<endl;
    }
    

    return 0;
}