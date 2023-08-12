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

    int r=0,l=0;
    for (int i = 1; i < n; i++)
    {
        if(i<r){
            z[i] = min(r-i,z[i-l]);
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
            z[i]++;
        }

        if(i+z[i]>r){
            l = i ;
            r = i + z[i];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<z[i]<<" ";
    // }
    
    // cout<<endl;
    vi ans;

    for (int i = 1; i <n; i++)
    {
        int j = i;
        for (; j < n; j+=i)
        {
            if((n-j)<=i && z[j]==n-j){
                ans.push_back(i);
            }
            if(z[j]<i){
                break;
            }
        }
        
    }
    ans.push_back(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
    
    

    return 0;
}