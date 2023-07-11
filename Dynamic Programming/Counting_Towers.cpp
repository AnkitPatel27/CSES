#include <bits/stdc++.h>
using namespace std;
 
const long long p = 1e9+7;
 
int  main(){
    int n;
    cin>>n;
    int maxN=0;
    
    vector <int> test(n);
    
    for(int i=0;i<n;i++){
        cin>>test[i];
        maxN = max(maxN,test[i]);
    }
    
    vector<long long>open(maxN+1);
    vector<long long>closed(maxN+1);
    open[1]=1;
    closed[1]=1;
    for(int i=2;i<=maxN;i++){
        closed[i] = (4ll*closed[i-1]+open[i-1])%p;
        open[i] = (2ll*open[i-1] + closed[i-1])%p;
    }
    
    for(auto ind:test){ 
        cout<<(open[ind]+closed[ind])%p<<"\n";
    }
    
    
    return 0;
}