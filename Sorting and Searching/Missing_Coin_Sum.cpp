#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long sum = 0;

    for (int i = 0; i < n; i++){
        if(sum+1-a[i]>=0){
            sum+=a[i];
        }
        else{
            cout<<sum+1<<endl;
            return 0;
        }
    }
    cout<<sum+1<<endl;
    return 0;
}