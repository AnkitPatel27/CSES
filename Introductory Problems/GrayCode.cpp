#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    for(int i =0;i<(1<<n);i++){
        for (int j = n; j>0; j--)
        {
            if(j==0){
                cout<<((i>>(j-1))&1);
            }
            else{
                cout<<(((i>>j)&1)^((i>>(j-1))&1));
            }
        }
        cout<<endl;
        
    }

    return 0;
}


