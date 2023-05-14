#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int test,cases=0;
    cin>>test;
    while(test){
        test--;
        cases++;
        int n,m;
        cin>>n;
        cin>>m;
        vector <int> list(n+1,0);
        for (int i = 0; i < m; i++)
        {
            int x,y;
            cin>>x>>y;
            list[x]++;
            list[y]++;
        }
        int d1=-1,d2=-1,d1d2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if(list[i]!=1){
                d1++;
            }
            else{
                d1d2++;
            }
        }
        
        d2 = d1d2/d1;
        cout<<d1<<" "<<d2<<endl;
    }
    return 0;
}