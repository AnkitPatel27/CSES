#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int arr[n]={0};
    int ind[n+1]={0};
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        ind[arr[i]] = i+1;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if(ind[i]<ind[i-1]){
            ans+=1;
        }
    }
    
    cout<<ans;
    return 0;
}