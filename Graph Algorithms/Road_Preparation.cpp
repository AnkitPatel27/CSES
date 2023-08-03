#include <bits/stdc++.h>
using namespace std;
 
int findParent(int from,vector <int> &par){
    while(from!=par[from]){
        from = par[from];
    }
    return from;
}

void unionSet(int from, int to, int parFrom, int parTo, vector<int> &par, vector<int> &rank) {
    if (rank[parFrom] > rank[parTo]) {
        par[parTo] = parFrom;
        rank[parFrom]+=rank[parTo];
    } else if (rank[parFrom] < rank[parTo]) {
        par[parFrom] = parTo;
        rank[parTo]+=rank[parFrom];
    } else {
        par[parTo] = parFrom;
        rank[parFrom]+=rank[parTo];
    }
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector <pair<long long,pair<int,int>>> edge(m);

    for (int i = 0; i < m; i++)
    {
        cin>>edge[i].second.first>>edge[i].second.second>>edge[i].first;
    }

    sort(edge.begin(),edge.end());

    vector <int> par(n+1),rank(n+1,1);
    
    for (int i = 1; i <=n; i++)
    {
        par[i] = i;
    }
    
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        int from = edge[i].second.first;
        int to = edge[i].second.second;
        int parFrom = findParent(from,par);
        int parTo = findParent(to,par);
        // cout<<"parfrom : "<<parFrom<<" parto : "<<parTo<<" ";
        // cout<<"w : "<<edge[i].first<<endl;
        if(parTo!=parFrom){
            ans+=edge[i].first;
            unionSet(from,to,parFrom,parTo,par,rank);
        }
    }
    int k = findParent(1,par);
    if(rank[k]!=n){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<ans<<endl;

    return 0;
}