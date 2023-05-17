#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    map<int,int> res;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        res[x]++;
        res[y]--;
    }
    
    int count = 0;
    int ans = 0;
    for(auto it = res.begin();it!=res.end();it++){
        count+=it->second;
        ans = max(ans,count);
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}