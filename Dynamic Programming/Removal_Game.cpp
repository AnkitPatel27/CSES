#include <bits/stdc++.h>
using namespace std;
 
 
long long f1[5000][5000],f2[5000][5000];
 
int main()
{
    int n;
    cin>>n;
    vector<long long> a(n);
   
    for(int i=0;i<n;i++){cin>>a[i];};
    
    for(int i =0;i<n;i++){
        f1[i][i] = a[i];
        f2[i][i] = 0;
    }
    
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            f1[i][j] = max(a[i]+f2[i+1][j],a[j]+f2[i][j-1]);
            f2[i][j] = min(f1[i+1][j],f1[i][j-1]);
            // cout<<f1[i][j]<<" ";
        }
        // cout<<endl;
    }
   
    cout<<f1[0][n-1]<<endl;
    
   
    return 0;
}