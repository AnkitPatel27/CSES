#include <bits/stdc++.h>
using namespace std;
 
int findParent(int x,vector <int> &par){
    if(par[x]==x){
        return x;
    }

    return par[x] = findParent(par[x],par);
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector <int> par(n+1),rank(n+1,1);

    for (int i = 1; i <=n; i++)
    {
        par[i] = i;
    }

    int maxSize = 1;
    int component = n;

    int x,y;
    for (int i = 0; i < m; i++)
    {
        cin>>x>>y;

        int parx = findParent(x,par);
        int pary = findParent(y,par);

        if(parx!=pary){
            component--;
            if(rank[parx]>=rank[pary]){
                par[pary] = parx;
                rank[parx]+=rank[pary];
            }
            else if(rank[pary]>rank[parx]){
                par[parx] = pary;
                rank[pary]+=rank[parx];
            }
            maxSize = max(maxSize,max(rank[pary],rank[parx]));
        }
        cout<<component<<" "<<maxSize<<endl;
    }
    

    

    return 0;
}