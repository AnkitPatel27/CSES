#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t){
        t--;
        long long y,x;
        cin>>x;
        cin>>y;
        
        if(y>x){
            if(y&1){
                long long ans = y*y-x+1;        
                cout<<ans<<endl;
            }
            else{
                long long ans = (y-1)*(y-1) +x;
                cout<<ans<<endl;
            }
        }
        else{
            if(x&1){
                long long ans = (x-1)*(x-1)+y;        
                cout<<ans<<endl;
            }
            else{
                long long ans = x*x -y+1;
                cout<<ans<<endl;
            }
        }
    }
}