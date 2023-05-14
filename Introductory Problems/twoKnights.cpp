#include <bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin>>t;
    for (int i = 1; i<=t; i++)
    {
        long long n = ((long long)i)*((long long)i);
        n = ((n)*(n-1))/2;
        n = n - ((long long)4)*(((long long)(i-2))*((long long)(i-1)));
        cout<<n<<"\n";
    }
    
    return 0;
}