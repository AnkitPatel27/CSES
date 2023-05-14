#include <bits/stdc++.h>
using namespace std;

bool canPut(int x,int y,vector <vector <char>> &chess){
    
    for (int i = y; i < 8; i++)
    {
        if(chess[x][i]=='-'){
            return false;
        }
    }
    for (int i = y; i >=0; i--)
    {
        if(chess[x][i]=='-'){
            return false;
        }
    }
    for (int i = x; i >=0; i--)
    {
        if(chess[i][y]=='-'){
            return false;
        }
    }
    for (int i = 1; i <= 8; i++)
    {
        if(x-i>=0 && y+i<8){
            if(chess[x-i][y+i]=='-'){
                return false;
            }
        }
        else{
            break;
        }
    }
    for (int i = 1; i <= 8; i++)
    {
        if(x-i>=0 && y-i>=0){
            if(chess[x-i][y-i]=='-'){
                return false;
            }
        }
        else{
            break;
        }
    }
    return true;
    
}

int dp(int x,int y,int queens,vector <vector <char>> &chess){
    if(queens==0){
        // for (int i = 0; i < 8; i++)
        // {
        //     for (int j = 0; j < 8; j++)
        //     {
        //         cout<<chess[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return 1;
    }
    if(x>=8){
        return 0;
    }
    if(y>=8){
        return 0;
    }
    // cout<<"x : "<<x<<"y : "<<y<<endl;
    if(chess[x][y]=='.' && canPut(x,y,chess)){
        chess[x][y] = '-';
        int z = dp(x+1,0,queens-1,chess);
        chess[x][y] = '.';
        int t = dp(x,y+1,queens,chess);
        return z+t;
    }
    else if(chess[x][y]=='.'){
        int t = dp(x,y+1,queens,chess);
        return t;
    }
    else if(chess[x][y]=='*'){
        return dp(x,y+1,queens,chess);
    }
    // return 0;
}

int main(){
    vector <vector <char>> chess(8,vector <char> (8));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin>>chess[i][j];
        }
    }

    int k = dp(0,0,8,chess);
    cout<<k<<endl;
    return 0;
}