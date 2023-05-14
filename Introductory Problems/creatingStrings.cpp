#include <bits/stdc++.h>
using namespace std;


void create_strings(string s,int j){
    int n = s.length();
    
    if(j==n){
        cout<<s<<endl;
        return;
    }

    sort(s.begin()+j,s.end());
    
    set <pair<char,char>> chk;
    for (int i = j; i < n; i++)
    {
        if(chk.find({s[j],s[i]})==chk.end()){
            swap(s[j],s[i]); 
            create_strings(s,j+1);
            swap(s[j],s[i]);
            chk.insert({s[j],s[i]});
        } 
    }
    
}

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int ans=1;
    vector <int> freq(26,0);
    for (int i = 0; i < n; i++)
    {
        freq[s[i]-'a']++;
    }
    
    for (int i = 2; i <= n; i++)
    {
        ans*=i;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if(freq[i]>1){
            for (int j = 2; j <= freq[i]; j++)
            {
                ans = ans/j;
            }
        }
    }
    
    cout<<ans<<endl;
    sort(s.begin(),s.end());
    create_strings(s,0);
    return 0;
}