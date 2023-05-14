#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int k = 5;
    int res =0;
    while(k<=n){
        res+=n/k;
        k = k*5;
    }
    cout<<res<<endl;
    return 0;
}