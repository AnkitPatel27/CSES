#include <bits/stdc++.h>
using namespace std;
 
int dp(int root,vector <int>  &ans,vector <vector <int>>  &child){
    if(child[root].size()==0){
        ans[root]=0;
        return 1;
    }
    int total = 0;
    for(int nxt : child[root]){
        total+=dp(nxt,ans,child);
    }

    ans[root] = total;
    return total+1; 
}

int main(){
    int n;
    cin>>n;
    
    vector <vector <int>> child(n+1);

    for (int i = 2; i <= n; i++)
    {
        int par;
        cin>>par;
        child[par].push_back(i);
    }

    // cout<<"hua\n";
    
    vector <int> ans(n+1,0);
    dp(1,ans,child);   
    // cout<<"hua2\n";

    for (int i = 1; i <=n; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}