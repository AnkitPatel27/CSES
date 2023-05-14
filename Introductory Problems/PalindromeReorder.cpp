#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    vector <int> freq(26,0);
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        freq[s[i]-'A']++;
    }

    bool oddone = false;
    int index = -1;
    for (int i = 0; i < 26; i++)
    {
        if((freq[i]&1)==1){
            if(oddone){
                cout<<"NO SOLUTION\n";
                return 0;
            }
            oddone = true;
            index = i;
        }
    }
    
    for (int i = 0; i < 26; i++)
    {
        if(i!=index){
            for (int j = 0; j < freq[i]/2; j++)
            {
                cout<<char(65+i);
            }
        }
    }

    if(oddone){
        for (int i = 0; i < freq[index]; i++)
        {
            cout<<char(65+index);
        }
    
    }

    for (int i = 25; i >=0; i--)
    {
        if(i!=index){
            for (int j = 0; j < freq[i]/2; j++)
            {
                cout<<char(65+i);
            }
        }
    }
    
    
    return 0;
}