#include <bits/stdc++.h>
using namespace std;
 
void dfs(int x,int y,int n,int m,vector<vector<char>> &g,vector<vector<int>> &r){
    // cout<<x<<" : y :"<<y<<endl;
    if(x>=n || y>=m || x<0 || y<0){
        return;
    }
    
    if(r[x][y] == 1 || g[x][y]=='#'){
        return;
    }
    
    int dpx[4] = {1,-1,0,0};
    int dpy[4] = {0,0,1,-1};
    
    r[x][y] = 1;
    
    for (int i = 0; i < 4; i++) {
        dfs(x+dpx[i],y+dpy[i],n,m,g,r);    
    }
    
}
 
int main(){
    
    int n,m;
    cin>>n>>m;
    
    vector<vector <char>> g(n,vector<char> (m));
    vector<vector <int>> r(n,vector<int> (m,0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>g[i][j];
        }
    }
    
    int numRooms = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(g[i][j] == '.' && r[i][j]==0){
                dfs(i,j,n,m,g,r);
                numRooms++;
            }
            // cout<<endl;
        }
    }
    cout<<numRooms<<endl;
    return 0;
}