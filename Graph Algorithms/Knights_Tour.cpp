#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
vvl vis(8,vl(8,0));
int dpx[] = {2,2,-2,-2,1,-1,1,-1};
int dpy[] = {1,-1,1,-1,2,2,-2,-2};

int neighbour(int x,int y){

    int k = 0;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dpx[i];
        int ny = y + dpy[i];
        if(nx>=0 && nx<8 && ny>=0 && ny<8  && vis[nx][ny]==0){
            k++;
        }
    }
    return k;
}

auto rng = default_random_engine();
bool dfs(int x,int y,int p){
    // cout<<x<<y<<endl;
    int ind = -1;
    int neigh = 9;
    vis[x][y] = p;

    if(p==64){
        return true;
    }
    
    vector<int> index(8);
    iota(index.begin(), index.end(), 0);

    shuffle(index.begin(), index.end(), rng);
    for(int i1=0;i1<8;i1++){
        int i = index[i1];
        int nx = x+dpx[i];
        int ny = y+dpy[i];

        if(nx>=0 && nx<8 && ny>=0 && ny<8  && vis[nx][ny]==0){
            int ans = neighbour(nx,ny);
            if(ans<neigh){
                ind = i;
                neigh = ans;
            }
        }
    }
    if(ind==-1){
        // cout<<"p :"<<p<<endl;
        return false;
    }

    int nx = x+dpx[ind];
    int ny = y+dpy[ind];

    return dfs(nx,ny,p+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x,y;
    cin>>x>>y;
    
    while(!dfs(y-1,x-1,1)){
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                vis[i][j]=0;
            }
            
        }
        
    }

    for(auto a:vis){
        for(int v:a){
            cout<<v<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}