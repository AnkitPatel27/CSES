#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int next[n+1], vis[n+1]={0};

    for (int i = 1; i <=n; i++){cin>>next[i];}

    
    for (int i = 1; i <=n; i++)
    {
        if(vis[i]==0){
            int at = i;
            int intial = at;
            int len = 0;
            while(vis[at] == 0){
                // cout<<"vis : "<<at<<endl;
                vis[at] = -1;
                at = next[at];
                len++;
            }

            if(vis[at]!=-1){
                while(intial!=at && vis[intial]==-1){
                    vis[intial] = len + vis[at]; 
                    intial = next[intial];
                    len--;
                }
            }
            else{
                int cycleStart = at;
                while(intial!=cycleStart){
                    vis[intial] = len;
                    // incycle[intial] = -1;
                    intial = next[intial];
                    len--;
                }

                at = cycleStart;
                vis[at] = len;
                // incycle[at] = 1;
                at = next[at];


                while(at != cycleStart){
                    // incycle[at] = 1;
                    vis[at] = len;
                    at = next[at];
                }
            }

        }
    }
    
    for (int i = 1; i <=n; i++){cout<<vis[i]<<" ";}
    

    return 0;
}
