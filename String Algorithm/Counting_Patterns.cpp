#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)

int getLink(int V);
int go(int V,char ch);


// Aho Corasick Algorithm
string s;
int k;
int cnt = 0;
vi patTrieNode((int)5e5+12,-1);


struct Vertex
{
    int next[26];    
    int go[26];
    bool output = false; 
    char parK = '$';   
    int exitDone = -1;
    vi stringIndex;
    int parindex = -1;
    int suffixLink  = -1;
    ll freq = 0;

    Vertex(){
        for (int i = 0; i < 26; i++)
        {
            next[i] = -1;
            go[i] = -1;
        }
        
    }


};

vector <Vertex> trie(1000000);

void addString(int V,string s,int p){
    int n = (int)s.size();

    for (int i = 0; i < n; i++)
    {
        if(trie[V].next[s[i]-'a']==-1){
            cnt++;
            trie[V].next[s[i]-'a'] = cnt;
        }
        int par = V;
        V = trie[V].next[s[i]-'a'];
        
        trie[V].parK = s[i];
        trie[V].parindex = par;
        
    }
    patTrieNode[p] = V;
    trie[V].output = true;
    trie[V].stringIndex.push_back(p);
}


int getLink(int V){
    if(trie[V].suffixLink==-1){
        if(V==0 || trie[V].parindex==0){
            trie[V].suffixLink = 0;    
        }
        else{
            trie[V].suffixLink =  go(getLink(trie[V].parindex),trie[V].parK);
        }
    }
    return trie[V].suffixLink;
}

int go(int V,char ch){
    if(trie[V].go[ch-'a']==-1){
        if(trie[V].next[ch-'a']!=-1){
            trie[V].go[ch-'a'] = trie[V].next[ch-'a']; 
        }
        else{
            trie[V].go[ch-'a'] = (V==0)?0:go(getLink(V),ch);
        }
    }
    return trie[V].go[ch-'a'];
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    cin>>s>>k;
    int n= s.length();
    trie[0].suffixLink = 0;

    // cout<<"start\n";
    FOR(0,k-1,1){
        string temp;
        cin>>temp;
        addString(0,temp,i);
    }

    // cout<<"start\n";

    int at = 0;
    trie[at].freq++;
    for (int i = 0; i < n; i++)
    {
        // cout<<"go called\n";
        at = go(at,s[i]);
        trie[at].freq++;
    }
    
    vi bfs;
    queue<int> q;
    q.push(0);
    while(!q.empty()){

        int node = q.front();
        bfs.push_back(node);
        q.pop();

        for (int i = 0; i < 26; i++)
        {
            if(trie[node].next[i]!=-1){
                q.push(trie[node].next[i]);
            }
        }
        
    }

    for (int i = bfs.size() - 1; i >= 0; i--)
    {
        int node = bfs[i];
        int suffix = getLink(node);
        trie[suffix].freq+=trie[node].freq;
    }
    


    for (int i = 0; i < k; i++)
    {
        cout<<trie[patTrieNode[i]].freq<<"\n";
    }
    
    
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// #define vvi vector<vector<int>>
// #define vi vector<int>
// #define vl vector<long long>
// #define vvl vector<vector<long long>>
// #define pii pair<int,int>
// #define FOR(start, end, step) for (int i = start; i <= end; i += step)

// int getLink(int V);
// int go(int V,char ch);


// // Aho Corasick Algorithm
// string s;
// int k;
// int cnt = 0;
// vi patTrieNode((int)5e5+12,0);

// struct Vertex
// {
//     int next[26];    
//     int go[26];
//     bool output = false; 
//     char parK = '$';   
//     int exitDone = -1;
//     vi stringIndex;
//     int parindex = -1;
//     int suffixLink  = -1;
//     int
//     Vertex(){
//         for (int i = 0; i < 26; i++)
//         {
//             next[i] = -1;
//             go[i] = -1;
//         }
        
//     }


// };

// vector <Vertex> trie(1000000);

// void addString(int V,string s,int p){
//     int n = (int)s.size();

//     for (int i = 0; i < n; i++)
//     {
//         // cout<<"V : "<<V<<endl;
//         if(trie[V].next[s[i]-'a']==-1){
//             cnt++;
//             trie[V].next[s[i]-'a'] = cnt;
//         }
//         int par = V;
//         V = trie[V].next[s[i]-'a'];
        
//         trie[V].parK = s[i];
//         trie[V].parindex = par;
        
//     }

//     trie[V].output = true;
//     trie[V].stringIndex.push_back(p);
//     // cout<<"True Output :"<<V<<" : "<<trie[V].output<<" : "<<trie[V].stringIndex <<endl;
// }


// int getLink(int V){
//     // cout<<V<<" : "<<trie[V].parindex<<" : "<<trie[V].suffixLink<<endl;
//     if(trie[V].suffixLink==-1){
//         if(V==0 || trie[V].parindex==0){
//             trie[V].suffixLink = 0;    
//         }
//         else{
//             trie[V].suffixLink =  go(getLink(trie[V].parindex),trie[V].parK);
//         }
//     }

//     // cout<<V<<" : "<<trie[V].parindex<<" : "<<trie[V].suffixLink<<endl;
//     return trie[V].suffixLink;
// }

// int go(int V,char ch){
//     if(trie[V].go[ch-'a']==-1){
//         if(trie[V].next[ch-'a']!=-1){
//             trie[V].go[ch-'a'] = trie[V].next[ch-'a']; 
//         }
//         else{
//             trie[V].go[ch-'a'] = (V==0)?0:go(getLink(V),ch);
//         }
//     }
//     return trie[V].go[ch-'a'];
// }

// void travelExits(int V){
//     while(V!=0 && trie[V].exitDone!=1){
//         // cout<<" exitV : "<<V<<endl;
//         if(trie[V].output == true){
//             // patPres[trie[V].stringIndex] = 1;
//             for (int i = 0; i < trie[V].stringIndex.size(); i++)
//             {
//                 patPres[trie[V].stringIndex[i]] = 1;
//             }
            
//         }
//         trie[V].exitDone = 1;
//         V = getLink(V);
//     }
// }

// int main(){
//     // ios_base::sync_with_stdio(false);
//     // cin.tie(NULL);

//     cin>>s>>k;
//     int n= s.length();
//     trie[0].suffixLink = 0;

//     // cout<<"start\n";
//     FOR(0,k-1,1){
//         string temp;
//         cin>>temp;
//         addString(0,temp,i);
//     }

//     // cout<<"start\n";

//     int at = 0;
//     for (int i = 0; i < n; i++)
//     {
//         // cout<<"go called\n";
//         at = go(at,s[i]);
//         // cout<<"exits : "<<at<<"\n";
//         travelExits(at);
//     }
    
//     // for (int i = 0; i < k; i++)
//     // {
//     //     // cout<<patPres[i]<<" ";
//     //     if(patPres[i]==1){
//     //         cout<<"YES\n";
//     //     }
//     //     else{
//     //         cout<<"NO\n";
//     //     }
//     // }
    





//     return 0;
// }