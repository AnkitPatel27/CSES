#include <bits/stdc++.h>
using namespace std;

int compar(pair<int,int> &a,pair<int,int> &b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    return a.second>b.second;
}


int compar2(pair<int,int> &a,pair<int,int> &b){
    if(a.first!=b.first){
        return a.first>b.first;
    }
    return a.second<b.second;
}

int main(){
    int n;
    cin>>n;
    vector <pair<int,int>> r;
    map <string,int> index;
    int contains[n]={0},contained[n]={0};
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        r.push_back({x,y});
        index[to_string(x)+"+"+to_string(y)]=i;
    }

    sort(r.begin(),r.end(),compar);
    int curMax = r[0].second;
    for (int i = 1; i < n; i++)
    {
        // cout<<r[i].first<<" : "<<r[i].second<<endl;
        if(curMax>=r[i].second){
            int ind = index[to_string(r[i].first)+"+"+to_string(r[i].second)];
            contained[ind]=1;
        }
        else{
            curMax=r[i].second;
        }
    }
    
    sort(r.begin(),r.end(),compar2);
    int curSmall = r[0].second;
    for (int i = 1; i < n; i++)
    {
        // cout<<r[i].first<<" : "<<r[i].second<<endl;
        if(curSmall<=r[i].second){
            int ind = index[to_string(r[i].first)+"+"+to_string(r[i].second)];
            contains[ind]=1;
        }
        else{
            curSmall=r[i].second;
        }
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