#include <bits/stdc++.h>
using namespace std;

int p[1001][1001];
void build(int i,int x1,int y1,int x2,int y2,int tree[]){
    if(x1==x2 && y1==y2){
        tree[i] = p[x1][y1];
        return;
    }
    if(x1==x2){
        int mid = (y1+y2)/2;

        build(4*i-2,x1,y1,x2,mid,tree);
        build(4*i-1,x1,mid+1,x2,y2,tree);
        tree[i] = tree[4*i-2]+tree[4*i-1];
        return;
    }   
    if(y1==y2){
        int mid = (x1+x2)/2;

        build(4*i-2,x1,y1,mid,y2,tree);
        build(4*i-1,mid+1,y1,x2,y2,tree);
        tree[i] = tree[4*i-2]+tree[4*i-1];
        return;
    }   
    
    int midx = (x1+x2)/2;
    int midy = (y1+y2)/2;

    build(4*i-2,x1,y1,midx,midy,tree);
    build(4*i-1,x1,midy+1,midx,y2,tree);
    build(4*i,midx+1,y1,x2,midy,tree);
    build(4*i+1,midx+1,midy+1,x2,y2,tree);
    
    tree[i] = tree[4*i-2]+tree[4*i-1]+tree[4*i]+tree[4*i+1];
}

void update(int i,int x1,int y1,int x2,int y2,int x,int y,int tree[]){
    if(x1==x2 && y1==y2){
        if(tree[i]==0){
            tree[i] = 1;
        }
        else{
            tree[i] = 0;
        }
        return;
    }
    if(x1==x2){
        int mid = (y1+y2)/2;
        if(y<=mid){
            update(4*i-2,x1,y1,x2,mid,x,y,tree);
        }
        else{
            update(4*i-1,x1,mid+1,x2,y2,x,y,tree);
        }
        tree[i] = tree[4*i-2]+tree[4*i-1];
        return;
    }   
    if(y1==y2){
        int mid = (x1+x2)/2;
        if(x<=mid){
            update(4*i-2,x1,y1,mid,y2,x,y,tree);
        }
        else{
            update(4*i-1,mid+1,y1,x2,y2,x,y,tree);
        }
        tree[i] = tree[4*i-2]+tree[4*i-1];
        return;
    }   
    
    int midx = (x1+x2)/2;
    int midy = (y1+y2)/2;
    
    if(x<=midx && y<=midy){
        update(4*i-2,x1,y1,midx,midy,x,y,tree);
    }
    else if(x<=midx && y>midy){
        update(4*i-1,x1,midy+1,midx,y2,x,y,tree);
    }
    else if(x>midx && y<=midy){
        update(4*i,midx+1,y1,x2,midy,x,y,tree);
    }
    else{
        update(4*i+1,midx+1,midy+1,x2,y2,x,y,tree);
    }
    tree[i] = tree[4*i-2]+tree[4*i-1]+tree[4*i]+tree[4*i+1];
}

int query(int i,int x1,int y1,int x2,int y2,int tarx1,int tary1,int tarx2,int tary2,int tree[]){
    if(tarx2<x1 || tary2<y1 || x2<tarx1 || y2<tary1){
        return 0;
    }
    if(tarx1<=x1 && tary1<=y1){
        if(x2<=tarx2 && y2<=tary2){
            return tree[i];
        }
    }

    if(x1==x2){
        int mid = (y1+y2)/2;
        int a = query(4*i-2,x1,y1,x2,mid,tarx1,tary1,tarx2,tary2,tree);
        int b = query(4*i-1,x1,mid+1,x2,y2,tarx1,tary1,tarx2,tary2,tree);
        return a + b;
    }   
    if(y1==y2){
        int mid = (x1+x2)/2;
        int a = query(4*i-2,x1,y1,mid,y2,tarx1,tary1,tarx2,tary2,tree);
        int b =query(4*i-1,mid+1,y1,x2,y2,tarx1,tary1,tarx2,tary2,tree);
        return a+b;
    }   
    
    int midx = (x1+x2)/2;
    int midy = (y1+y2)/2;

    int a1 = query(4*i-2,x1,y1,midx,midy,tarx1,tary1,tarx2,tary2,tree);
    int a2 = query(4*i-1,x1,midy+1,midx,y2,tarx1,tary1,tarx2,tary2,tree);
    int a3 = query(4*i,midx+1,y1,x2,midy,tarx1,tary1,tarx2,tary2,tree);
    int a4 = query(4*i+1,midx+1,midy+1,x2,y2,tarx1,tary1,tarx2,tary2,tree);
    return a1+a2+a3+a4;
}

int main(){
    int n,q;
    cin>>n>>q;
    int tree[4*(n+1)*(n+1)]={0};
    
    char k;
    for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
            cin>>k;
            p[i][j]=0;
            if(k=='*'){
                p[i][j] = 1;
            }
       }
    }
    
    build(1,1,1,n,n,tree);
    
    int t,x,y,x1,x2,y1,y2;
    for (int i = 0; i < q; i++)
    {
        cin>>t;
        if(t==1){
            cin>>x>>y;
            update(1,1,1,n,n,x,y,tree);
        }
        else{
            cin>>x1>>y1>>x2>>y2;
            cout<<query(1,1,1,n,n,x1,y1,x2,y2,tree)<<"\n";
        }
    }
    
    
    return 0;
}