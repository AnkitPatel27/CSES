#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

void generate_mask(int i,int n,int mask,vector <int> &gmask){
    if(i==n){
        gmask.push_back(mask);
        return;
    }
    if(!(mask&(1<<i))){
        mask = mask^(1<<i);
        generate_mask(i+1,n,mask,gmask);
        mask = mask^(1<<i);
    }

    if(i<n-1 && !(mask&(1<<i)) && !(mask&(1<<(i+1)))){
        generate_mask(i+2,n,mask,gmask);
    }

    if((mask&(1<<i))){
        mask = mask^(1<<i);
        generate_mask(i+1,n,mask,gmask);
        mask = mask^(1<<i);
    }
}

vector <vector <int>> mem(1001,vector <int>(1<<11,-1));

int dp(int col,int mask,int m,int n){
    if(col==m){
        if(mask==0){
            return 1;
        }
        return 0;
    }

    if(mem[col][mask] != -1){
        return mem[col][mask];
    }

    vector<int> gmask;
    generate_mask(0,n,mask,gmask);
    int  ans = 0;
    for (int i = 0; i < gmask.size(); i++)
    {
        ans+=dp(col+1,gmask[i],m,n);
        ans%=MOD;
    }
    
    return mem[col][mask] = ans;

} 

int main(){
    int n,m;
    cin>>n>>m;

    cout<<dp(0,0,m,n);
    return 0;
}