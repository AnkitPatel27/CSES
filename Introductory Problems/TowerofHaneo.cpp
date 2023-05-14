#include <bits/stdc++.h>
using namespace std;

void hanoi(int n,int A ,int B,int C){
    if(n>0){
        hanoi(n-1,A,C,B);
        cout<<A<<" "<<C<<endl;
        hanoi(n-1,B,A,C);
    }
}

int main(){
    int n;
    cin>>n;
    cout<<(pow(2,n)-1)<<endl;
    hanoi(n,1,2,3);
    return 0;
}