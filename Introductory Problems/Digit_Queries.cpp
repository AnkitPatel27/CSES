#include <bits/stdc++.h>
using namespace std;
 
int dp(long long k){
    long long digit = 1;
    long long total = 0;
    long long pow1 = 1;
    while(total<1e19){
        if(k<=total+digit*(pow1*10ll-pow1)){
            // cout<<"dist : "<<(k-total-1ll)/digit<<" mod : "<<(k-total-1ll)%digit<<" : digit : "<<digit<<"   total  :"<<total <<" pow1 : "<<pow1<<" ";
            long long ans = ((k-total-1ll)/digit)+pow1;
            long long mod = digit-((k-total-1ll)%digit);
            long long ten = pow(10ll,mod-1ll);
            cout<<"ans : "<<ans<<" mod :"<<mod<<" ten "<<ten<<" :=> ";
            return (ans/ten)%10ll;
        }
        total += digit*(pow1*((long long)10)-pow1);
        // 9+2*(10*10-10)
        digit++;
        pow1 = pow1*((long long)10);
    }
    return 0;
}   
// 9+90*2

int main(){

    int test,cases=0;
    cin>>test;
    while(test){
        test--;
        cases++;
        long long k;
        cin>>k;
        cout<<dp(k)<<endl;
    }


    return 0;
}