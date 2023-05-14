#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        int a,b;
        cin>>a;
        cin>>b;
        
        if((a+b)%3==0 && min(a,b)*2>=max(a,b)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }
    return 0;
}