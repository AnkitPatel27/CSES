#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 

void lps(string &pat,vi &pi,int n){

    pi[0] = 0;

    for (int i = 1; i < pat.size(); i++)
    {
        int j = pi[i-1];

        while(j>0 && pat[j]!=pat[i]){
            j = pi[j-1];
        }

        if(pat[i]==pat[j]){
            j++; 
        }

        pi[i] = j;
    }
    
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s,pat;
    cin>>s>>pat;

    int n = pat.size();
    vi pi(n,0);

    int i =0;
    int j = 0;
    int ans = 0;

    lps(pat,pi,n);
    // for(int a : pi){
    //     cout<<a<<" ";
    // }
    // cout<<endl;
    while(i<s.size()){
        // cout<<i<<j<<endl;
        if(s[i]==pat[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j = pi[j-1];
            }
            else{
                i++;
            }
        }

        if(j==n){
            ans++;
            j =  pi[j-1];
        }
    }   

    cout<<ans<<endl;
    return 0;
}