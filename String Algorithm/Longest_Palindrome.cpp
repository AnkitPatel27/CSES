#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
//MANACHER ALGORITHM

void ManacherAlgo(string s,vi &p){
    int l=1,r =1;
    int n = (int)s.size();
    vector <int>  a(n+2,0);
    s = "<"+s+">";
    for (int i = 1; i <=n; i++)
    {
        // if(i<r){
        a[i] = max(0,min(r-i,a[l+r-i]));
        // }

        while(s[i+a[i]]==s[i-a[i]]){
            a[i]++;
        }

        if(i+a[i]>r){
            l = i - a[i];
            r = i + a[i];
        }
    }

    p = vector <int> (begin(a)+1,end(a)-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    
    string s;
    cin>>s;


    int n = s.size();
    string temp = "";

    for (int i = 0; i < n; i++)
    {
        temp+=string("#")+s[i];
    }
    temp+=string("#");
    // cout<<temp<<endl;
    
    int m = temp.size();
    vi z(n,0),a(m,0),evenL(n,0);

    ManacherAlgo(s,z);
    ManacherAlgo(temp,a);

    int maxlen = 0;
    int ind = -1;
    int even = -1;

    for (int i = 0; i < m; i+=2)
    {
        evenL[i/2] = a[i]-1; 
        // cout<<evenL[i/2]<<endl;
        if(evenL[i/2]>maxlen){
            maxlen = evenL[i/2];
            ind = i;
            even = 1;
        }
    }
    

    for (int i = 0; i < n; i++)
    {
        // cout<<2*z[i]-1<<endl;
        if((2*z[i]-1)>maxlen){
            maxlen = 2*z[i]-1;
            ind = i;
            even = 0;
        }
    }
    
    if(even==0){
        int l = ind-z[ind]+1;
        for (int i = 0; i < maxlen; i++)
        {
            cout<<s[i+l];
        }
    }
    else{
        int l = ind-a[ind]+1;
        maxlen = 2*a[ind]-1;
        for (int i = 0; i < maxlen; i++)
        {
            if(temp[i+l]!='#'){
                cout<<temp[i+l];
            }
        }
    }
    return 0;
}