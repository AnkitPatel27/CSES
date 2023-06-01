#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int x,n;
    cin>>x>>n;
    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin>>p[i];
    }

    multiset <int> length;
    multiset <int> lamp;
    lamp.insert(x);
    length.insert(x);
    for (int i = 0; i < n; i++)
    {
        auto y = lamp.lower_bound(p[i]);
        if(y==lamp.begin()){
            int len = *y;
            length.erase(length.find(len));
            lamp.insert(p[i]);
            length.insert(len-p[i]);
            length.insert(p[i]);
            cout<<*(length.rbegin())<<" ";
        }
        else{
            int alen = *y;
            y--;
            int blen = *y;
            int len = alen-blen;
            lamp.insert(p[i]);
            length.erase(length.find(len));
            length.insert(alen-p[i]);
            length.insert(p[i]-blen);
            cout<<*(length.rbegin())<<" ";
        }
    }
    


    
    return 0;
}