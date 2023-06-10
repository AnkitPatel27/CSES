#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
  
#define ordered_set tree<pair<long long ,long long>, null_type,less<pair<long long ,long long>>, rb_tree_tag,tree_order_statistics_node_update>


int main(){
    long long n,k;
    cin>>n>>k;
    long long x[n];
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
    }

    ordered_set s;
    for (int i = 0; i < k-1; i++)
    {
        s.insert({x[i],i});
    }
    if(k%2==1){
        for (int i = k-1; i < n; i++)
        {
            s.insert({x[i],i});
            cout<<(*s.find_by_order((k-1)/2ll)).first<<" ";
            s.erase(s.find({x[i-k+1],i-k+1}));
        }
    }
    else{
        for (int i = k-1; i < n; i++)
        {
            s.insert({x[i],i});
            cout<<min((*s.find_by_order((k)/2ll)).first,(*s.find_by_order((k-1)/2ll)).first)<<" ";
            s.erase(s.find({x[i-k+1],i-k+1}));
        }
    }
    
    return 0;
}