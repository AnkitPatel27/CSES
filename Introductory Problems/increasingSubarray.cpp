#include <bits/stdc++.h>
using namespace std;

int main(){
    long long ans = 0;
    int n;
    cin>>n;
    long long x;
    long long prev =0;
    cin>>x;
    prev =x;
    for (int i = 1; i < n; i++)
    {
        cin>>x;
        if(x<prev){
            ans+=prev-x;
        }
        else{
            prev = x;
        }
        // prev = max(prev,x);
    }
    cout<<ans;
    return 0;
}