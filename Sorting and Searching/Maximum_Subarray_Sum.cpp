#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n ;
    cin >> n;
    long long a[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    long long sum = 0;
    long long maxSum = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        sum+=a[i];
        maxSum = max(maxSum,sum);
        if(sum<0){
            sum = 0;
        }
    }
    cout<<maxSum<<endl;
    return 0;
}