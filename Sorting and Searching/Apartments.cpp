#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m,k;
    cin>>n;
    cin>>m;
    cin>>k;
    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i = 0; i < m; i++){
        cin>>b[i];
    }
    
    sort(a,a+n);
    sort(b,b+m);
    
    int j = 0;
    int count=0;
    for (int i = 0;j < m && i < n;)
    {
        if(a[i]-k<=b[j] && a[i]+k>=b[j]){
            count++;
            i++;
            j++;
        }
        else if(a[i]-k>b[j]){
            j++;
        }
        else{
            i++;
        }
    }

    cout<<count<<endl;
    

    return 0;
}