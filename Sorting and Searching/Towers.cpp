#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int k[n];
    for (int i = 0; i < n; i++)
    {
        cin>>k[i];
    }
    
    int ind[n]={0};

    multiset <int> s;
    s.insert(k[n-1]);
    for (int i = n-2; i >= 0; i--){
        auto lower = s.lower_bound(k[i]);
        if(lower==s.begin()){
            s.insert(k[i]);
            continue;
        }
        else {
            lower--;
            // cout<<"size : "<<s.size()<<" lower : "<<k[i]<<" : poped "<<*lower<<endl;
            s.erase(lower);
            s.insert(k[i]);
        }
        // lower--;
        // if(lower == s.begin() && *lower>){
        //     cout<<"size : "<<s.size()<<endl;
        //     s.insert(k[i]);
        //     continue;
        // }
        // else{
        //     s.erase(lower);
        // }

    }
    cout<<s.size()<<endl;
    return 0;
}