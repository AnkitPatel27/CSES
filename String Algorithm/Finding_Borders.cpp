#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;

    int n = s.size();

    vi z(n,0);

    int l = 0,r = 0;
    for (int i = 1; i < n; i++)
    {
        if(i<r){
            z[i] = min(z[i-l],r-i);
        }

        while(i+z[i]<n && s[i+z[i]]==s[z[i]]){
            z[i]++;
        }

        if(i+z[i]>r){
            l = i;
            r = i+z[i];
        }
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        if((z[i]+i)==n){
            cout<<z[i]<<" ";
        }
    }
    

    return 0;
}