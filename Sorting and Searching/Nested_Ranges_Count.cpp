#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int> , null_type, less<pair<int,int> >, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int compar(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    return a.second.first>b.second.first;
}


int compar2(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b){
    if(a.first!=b.first){
        return a.first>b.first;
    }
    return a.second.first<b.second.first;
}



int main(){
    int n;
    cin>>n;
    vector <pair<int,pair<int,int>>> r;
    int contains[n]={0},contained[n]={0};
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        r.push_back({x,{y,i}});
        // index[to_string(x)+"+"+to_string(y)]=i;
    }

    sort(r.begin(),r.end(),compar);
    int curMax = r[0].second.first;
    ordered_set s;
    s.insert({r[0].second.first,0});
    for (int i = 1; i < n; i++)
    {
        if(curMax>=r[i].second.first){
            // int ind = index[to_string(r[i].first)+"+"+to_string(r[i].second)];
            contained[r[i].second.second]=i-s.order_of_key({r[i].second.first,-1});
        }
        else{
            curMax=r[i].second.first;
        }
        s.insert({r[i].second.first,i});
    }
    
    sort(r.begin(),r.end(),compar2);
    int curSmall = r[0].second.first;
    ordered_set s1;
    s1.insert({r[0].second.first,0});
    for (int i = 1; i < n; i++)
    {
        if(curSmall<=r[i].second.first){
            contains[r[i].second.second]=s1.order_of_key({r[i].second.first+1,-1});
        }
        else{
            curSmall=r[i].second.first;
        }
        s1.insert({r[i].second.first,i});
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<contains[i]<<" ";
    }
    cout<<endl;
   
    for (int i = 0; i < n; i++)
    {
        cout<<contained[i]<<" ";
    }
    
    
    return 0;
}

// 1 6 
// 2 4 6
// 3 6 4 6    
// 4 8 4 6 8 0