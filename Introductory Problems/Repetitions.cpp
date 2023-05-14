#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int cur = 0;
    int maxlen =0;
    for (int i = 1; i < n; i++)
    {
        if(s[i]!=s[i-1]){
            maxlen = max(maxlen,i-cur);
            cur = i;
        }
    }
    maxlen = max(maxlen,n-cur);
    cout<<maxlen;
    return 0;
}