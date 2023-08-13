#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 


int n,k;
string s;
vl hash1((int)2e5+2,0),rhash((int)2e5+2,0),pow1((int)2e5+2,0),ipow((int)2e5+2,0);
ll mod = (ll)1e9+7; 
ll p = 31;

ll invPower(ll a){
    ll b = mod - 2;
    ll res = 1;
    while(b>0){
        if(b%2==1){
            res = (res*a)%mod;
        }
        a=(a*a)%mod;
        b/=2;
    }

    return res;
}

void powr(){
    pow1[0] = 1;
    ipow[0] = 1;
    FOR(1,n,1){
        pow1[i]=(pow1[(i-1)]*p)%mod;
        ipow[i] = invPower(pow1[i]);
    }
}

void updateFen(vl &a,int index,ll newVal){
    for (int i = index+1; i<=n; i+=(i&(-i)))
    {
        // cout<<" index : "<<index<<endl;
        a[i] = (a[i]+newVal)%mod;   
    }
}

ll queryFen(vl &a,int index){
    if(index<0){
        return 0ll;
    }
    ll res = 0;
    for (int i = index+1; i>0; i-=(i&(-i)))
    {
        res = (res+a[i])%mod;   
    }

    return res;
}

void rollhash(){
    for (int i = 0; i < n; i++)
    {
       updateFen(hash1,i,((s[i]-'a')*pow1[i])%mod);   
        updateFen(rhash,i,((s[n-i-1]-'a')*pow1[i])%mod);   
    }
}


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    cin>>n>>k;
    cin>>s;

    string temp = s;
    reverse(temp.begin(),temp.end());

    powr();
    rollhash();
    


    for (int i = 0; i < k; i++)
    {
        int a;
        cin>>a;

        if(a==1){
            int ind;
            char x;
            cin>>ind>>x;
            ind--;
            updateFen(hash1,ind,(((x-'a')-(s[ind]-'a'))*pow1[ind])%mod);
            updateFen(rhash,n-ind-1,(((x-'a')-(temp[n-ind-1]-'a'))*pow1[n-ind-1])%mod);
            temp[n-ind-1] = x;
            s[ind] = x;
        }
        else{
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            int len = y-x+1;
            if(len%2==0){
                int l=x;
                int r = (x+y)/2;
                // cout<<"start\n";
                ll ans = (((queryFen(hash1,r) - queryFen(hash1,l-1)+mod)%mod)*ipow[l])%mod;    
                // cout<<"Done\n";
                // cout<<"l : "<<l<<" r : "<<r<<endl;
                int rr = n-1-y;
                int rl = n-1-(r+1);
                // cout<<"l : "<<rl<<" r : "<<rr<<endl;
                ll ansl = (((queryFen(rhash,rl) - queryFen(rhash,rr-1)+mod)%mod)*ipow[rr])%mod;    
                // cout<<"ans: "<<ans<<" ansl : "<<ansl<<endl;
                if(ans==ansl){
                    cout<<"YES\n";
                }
                else{
                    cout<<"NO\n";
                }
            }
            else{
                int l=x;
                int r = ((x+y)/2)-1;
                // cout<<"start\n";
                ll ans = (((queryFen(hash1,r) - queryFen(hash1,l-1)+mod)%mod)*ipow[l])%mod;    
                // cout<<"Done\n";
                // cout<<"l : "<<l<<" r : "<<r<<endl;
                int rr = n-1-y;
                int rl = n-1-(r+2);
                // cout<<"l : "<<rl<<" r : "<<rr<<endl;
                ll ansl = (((queryFen(rhash,rl) - queryFen(rhash,rr-1)+mod)%mod)*ipow[rr])%mod;    
                // cout<<"ans: "<<ans<<" ansl : "<<ansl<<endl;
                if(ans==ansl){
                    cout<<"YES\n";
                }
                else{
                    cout<<"NO\n";
                }
            }
        }
        

    }
    

    return 0;
}