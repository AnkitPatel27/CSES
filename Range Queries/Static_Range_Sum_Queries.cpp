#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    int test, cases = 0;
    cin >> n;
    cin >> test;
    int a[n];
    long long sum[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    long long curSum = 0;
    for (int i = 0; i < n; i++)
    {
        curSum += (long long)a[i];
        sum[i] = curSum;
    }
 
    while (test)
    {
        test--;
        cases++;
        int a,b;
        cin>>a>>b;
        long long ans = sum[b-1];
        if(a-1>0)
            ans -= sum[a-2];
        cout<<ans<<endl;
    }
    return 0;
}