#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    
    //end start
    vector <pair<int,pair<int,long long>>> a(n+1);
    
    for(int i = 1;i<=n;i++){
        cin>>a[i].second.first>>a[i].first>>a[i].second.second;
    }
    
    a[0] = {0,{0,0}};
    
    sort(a.begin(),a.end());
    
    
    long long INF = LONG_MAX;
    vector<long long> endTime(n+1,INF),profit(n+1,INF);
    
    endTime[0] = 0;
    profit[0] = 0;
    
    int j = 0;
    for(int i=1;i<=n;i++){
        if(endTime[j]!=a[i].first){
            j++;
            endTime[j] = a[i].first;
            profit[j] = profit[j-1];
        }
        
        int searchTime = a[i].second.first-1;
        int ind = upper_bound(endTime.begin(),endTime.end(),searchTime)-endTime.begin();
        ind--;
        long long ans = a[i].second.second+profit[ind];
        profit[j] = max(profit[j],ans);
    }
    
    
    cout<<profit[j]<<endl;
    return 0;
}