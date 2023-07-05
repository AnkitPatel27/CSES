#include <bits/stdc++.h>
using namespace std;
 
struct BIT{
    vector<int> bit;
    int size;
    BIT(int n):bit(n+1),size(n){}

    void update(int i,int k){
        for (; i <= size; i+=i&(-i))
        {
            bit[i] += k;
        }
    }

    int query(int i){
        int ans = 0;
        for (; i >0; i-=i&(-i))
        {
            ans += bit[i];
        }
        return ans;
    }
};



int main(){
    int n,q;
    cin>>n>>q;
    vector <int> x(n+1);
    vector < vector <pair<int,int>>> query(n+1);

    for (int i = 1; i <= n; i++)
    {
        cin>>x[i];
    }
    for (int i = 1; i <= q; i++)
    {
        int a, b;
		cin >> a >> b;
        query[b].push_back({a,i});
    }

    BIT bit(n);
    map <int,int> mp;
    vector <int> solution(q+1,0);


    for (int i = 1; i <= n; i++)
    {
        if(mp.count(x[i])>0){
            bit.update(mp[x[i]],-1);
        }

        mp[x[i]] = i;
        bit.update(i,1);
        for(auto &q: query[i]){
            int l,r,index;
            r=i;
            l=q.first;
            index = q.second;

            solution[index] = bit.query(r);
            if(l>1){
                solution[index]-=(bit.query(l-1));
            } 
        }
    }
    
    for (int i = 1; i <= q; i++)
    {
        cout<<solution[i]<<"\n";
    }
    return 0;
}