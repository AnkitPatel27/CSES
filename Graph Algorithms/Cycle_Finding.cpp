#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    
    vector <pair <int,pair<int,long long>>> edges(m);

    for (int i = 0; i < m; i++)
    {
        cin>>edges[i].first>>edges[i].second.first>>edges[i].second.first;
    }

    vector <long long> dist(n+1,LLONG_MAX); 
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
        }
        
    }
    



    




    return 0;
}