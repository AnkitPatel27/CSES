#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    map <int,int> mp;
    int i=0,j=0;
    int maxLen = 0;
    while(j<n){
        if(mp.find(a[j]) == mp.end()){
            // cout<<"j : "<<j<<endl;
            mp[a[j]] = j;
            j++;
            // maxLen = max(maxLen,j-i);
        }
        else{
            // cout<<"i-j : "<<i-j<<endl;
            i = max(i,mp[a[j]]+1);
            mp[a[j]] = j;
            j++;
        }
        maxLen = max(maxLen,j-i);
    }
    maxLen = max(maxLen,j-i);
    cout<<maxLen<<endl;
    return 0;
}