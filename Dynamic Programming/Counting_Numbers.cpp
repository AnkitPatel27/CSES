#include <bits/stdc++.h>
using namespace std;
 
long long mem[21][10][2][2];
 
long long dp(int n,int pos,int x,bool leading_zero,bool tight,string num){
    // cout<<pos<<endl;
    if(pos==n){
        return 1ll;
    }
    
    if(x!=-1 && mem[pos][x][leading_zero][tight]!=-1ll){
        return mem[pos][x][leading_zero][tight];
    }
    
    int upper = tight?(num[pos]-'0'):9;
    
    long long ans =0;
    for (int i = 0; i <= upper; i++) {
        if(i==x && !leading_zero)
            continue;
        ans+=dp(n,pos+1,i,leading_zero&&i==0,tight&&i==upper,num);
    }
    if(x!=-1){
        mem[pos][x][leading_zero][tight] = ans;
    }
    return ans;
}
 
int main(){
    long long a,b;
    cin>>a>>b;
    string a1 = to_string(a-1ll);
    string b1 = to_string(b);
    
    // cout<<"S1 :"<<b1<<"\n";
    memset(mem,-1ll,sizeof mem);
    long long ans1 = dp(b1.size(),0,-1,true,true,b1);
    
    // cout<<"S1\n";
 
    memset(mem,-1ll,sizeof mem);
    long long ans2 = dp(a1.size(),0,-1,true,true,a1);
 
    cout<<ans1-ans2;
    
    
    return 0;
}
