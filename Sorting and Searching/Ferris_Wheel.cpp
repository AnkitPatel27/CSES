#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,w;
    cin>>n;
    cin>>w;
    int a[n],vis[n]={0};
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a,a+n);

    int i=0;
    int j = n-1;
    int ans =0;
    while(i<=j){
        if(a[i]+a[j]<=w){
            ans++;
            i++;
            j--;
        }
        else{
            j--;
            ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}