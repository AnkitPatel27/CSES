#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    stack <pair<int,int>> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        while(!st.empty() && st.top().first>=x){
            st.pop();
        }
        if(st.empty()){
            cout<<"0 ";
        }
        else{
            cout<<st.top().second<<" ";
        }
        st.push({x,i+1});
    }
     
    return 0;
}