#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    long long k = ((long long) n)*((long long)(n+1))/(2LL);
    if((k&1)==0){
        cout<<"YES\n";
        vector <int> set1,set2;
        long long sum = k/2;
        for(int i=n;i>0;i--){
            if(sum>=i){
                set1.push_back(i);
                sum -= (long long)i;
            }
            else{
                set2.push_back(i);
            }
        }
        cout<<set1.size()<<endl;
        for(int i=0;i<set1.size();i++){
            cout<<set1[i]<<" ";
        }
        cout<<endl;
        cout<<set2.size()<<endl;
        for(int i=0;i<set2.size();i++){
            cout<<set2[i]<<" ";
        }
    }
    else{
        cout<<"NO";
    }
    return 0;
}