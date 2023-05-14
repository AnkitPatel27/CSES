#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
    ll n,x;
    cin>>n;
    ll expect = (n*(n+1))/(2LL);
    for (int i = 0; i < n-1; i++)
    {
        cin>>x;
        expect -=x;
    }
    cout<<expect;
    return 0;
}