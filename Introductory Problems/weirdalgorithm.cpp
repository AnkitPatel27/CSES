#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if((n&((long long)1))==0){
            n /=((long long) 2);
        }
        else{
            n *=((long long)3);
            n++;
        }
        cout<<n<<" ";
    }
    
    return 0;
}