#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i+1;
    }
    
    while(a.size()>1){
        vector <int> temp; 
        for (int i = 0; i < a.size(); i++)
        {
            if(i%2==1){
                cout<<a[i]<<" ";
            }
            else{
                temp.push_back(a[i]);
            }
        }
        if(a.size()%2==0){
            a = temp;
        }
        else{
            int p = temp[temp.size()-1];
            temp.pop_back();
            a.clear();
            a.push_back(p);
            for (int i = 0; i < temp.size(); i++)
            {
                a.push_back(temp[i]);
            }
            
        }
        
    }
    cout<<a[0];
    return 0;
}