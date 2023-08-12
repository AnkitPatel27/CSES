#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vi divisors((int)1e6+2,0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        for (int i = 1; i*i <=x ; i++)
        {
            if(x%i==0){
                if(i*i==x){
                    divisors[i]++;
                }
                else{
                    divisors[i]++;
                    divisors[x/i]++;
                }
            }
        }
    }
    

    for (int i = divisors.size() - 1; i >= 0; i--)
    {
        if(divisors[i]>=2){
            cout<<i<<endl;
            break;
        }
    }
    
    return 0;
}