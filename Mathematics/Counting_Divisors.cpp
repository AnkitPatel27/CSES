#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)

int maxN = (int)1e6+1; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;cin >>n ;
    vi divisors(maxN,1);

    for (int i = 2; i <=maxN; i++)
    {
        for (int j = i; j <=maxN; j+=i)
        {
            divisors[j]++;
        }
        
    }
    

    while(n>0){
        int x;
        cin>>x;
        cout<<divisors[x]<<"\n";
        n--;
    }
    return 0;
}