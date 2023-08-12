#include <bits/stdc++.h>
using namespace std;


#define CUSTOM_FOR(start, end, step) for (int i = start; i <= end; i += step)

void hanoi(int n,int A ,int B,int C){
    if(n>0){
        //n-1 disks from A goes to C using B 
        hanoi(n-1,A,C,B);
        //last disk to from A to C
        cout<<A<<" "<<C<<endl;
        //n-1 disks from B goes to C using B 
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