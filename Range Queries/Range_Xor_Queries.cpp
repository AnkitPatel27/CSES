#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int test,cases=0,n;
    cin>>n;
    cin>>test;

    int a[n],prefixXor[n];
    int curXor = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]; 
        curXor = curXor^a[i];
        prefixXor[i] = curXor;
    }

    while(test){
        test--;
        cases++;
        int t1,t2;
        cin>>t1>>t2;
        t1--;
        t1--;
        t2--;
        int ans = prefixXor[t2];
        if(t1>=0){
            ans = ans^prefixXor[t1];
        }
        cout<<ans<<endl;
    }
    return 0;
}

