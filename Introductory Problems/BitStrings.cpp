#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int b;
    cin>>b;
    
    long long a = 2LL;
    long long k = 1e9+7;
    long long res = 1;

    while(b>0){
        if((b&1)==1){
            res = ((res%k)*(a%k))%k;
        }
        a = ((a%k)*(a%k))%k;
        b = b/2;
    }

    cout<<res<<endl;    
    return 0;
}