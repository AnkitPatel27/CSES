#include <bits/stdc++.h>
using namespace std;
 
set <int> ans;
 
vector <vector<int>> mem(100001,vector<int>(100,0));
 
void dp(int i,int sum, vector<int> &a){
    if(i==a.size()){
        ans.insert(sum);
        return;
    }
   
    if(mem[sum][i]!=0){
        return;
    }
    mem[sum][i] = 1;
    dp(i+1,sum,a);
    dp(i+1,sum+a[i],a);
   
}
 
 
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
   
    for(int i=0;i<n;i++){cin>>a[i];};
   
    dp(0,0,a);
    cout<<ans.size()-1<<endl;
    auto it = ans.begin();
    it++;
    for (; it !=ans.end(); ++it)
    {
        cout << *it<<" ";
    }
   
    return 0;
}