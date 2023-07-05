#include <bits/stdc++.h>
using namespace std;
 
long long diff(long long a,long long diff,long long n){
    return (n*(2ll*a+(n-1ll)*diff))/2ll;
}

void build(long long i,long long l,long long r,long long t[],long long tree[]){
    if(l==r){
        tree[i]=t[l];
        return;
    }
 
    long mid=(l+r)>>1;
    build(2*i,l,mid,t,tree);
    build(2*i+1,mid+1,r,t,tree);
    tree[i] = tree[2*i] + tree[2*i+1];
}

void update(long long i,long long l,long long r,long long x,long long y,long long t[],long long tree[],long long lazyStart[],long long lazyEnd[]){
    long mid=(l+r)>>1;
    if(lazyStart[i]>0){
        tree[i] += diff(lazyStart[i],lazyEnd[i],r-l+1ll);
        if(l!=r){
            lazyStart[2*i] += lazyStart[i];
            lazyEnd[2*i] += lazyEnd[i];
            
            lazyStart[2*i+1] += lazyEnd[i]*(mid+1-l)+lazyStart[i];
            lazyEnd[2*i+1] += lazyEnd[i];
        }
        lazyEnd[i] = 0;
        lazyStart[i] = 0;
    }
    if(y<l || x>r){
        return;
    }
    if(x<=l && r<=y){
        lazyStart[i]=l-x+1;
        lazyEnd[i]=1;
        tree[i] += diff(lazyStart[i],lazyEnd[i],r-l+1ll);
        if(l!=r){
            lazyStart[2*i] += lazyStart[i];
            lazyEnd[2*i] += lazyEnd[i];
            
            lazyStart[2*i+1] += lazyEnd[i]*(mid+1-l)+lazyStart[i];
            lazyEnd[2*i+1] += lazyEnd[i];
        }
        lazyEnd[i] = 0;
        lazyStart[i] = 0;
        return;
    }

    update(2*i,l,mid,x,y,t,tree,lazyStart,lazyEnd);
    update(2*i+1,mid+1,r,x,y,t,tree,lazyStart,lazyEnd);
    tree[i] = tree[2*i] + tree[2*i+1];
}

long long query(long long i,long long l,long long r,long long x,long long y,long long tree[],long long lazyStart[],long long lazyEnd[]){
     long mid=(l+r)>>1;
    if(lazyStart[i]>0){
        tree[i] += diff(lazyStart[i],lazyEnd[i],r-l+1ll);
        if(l!=r){
            lazyStart[2*i] += lazyStart[i];
            lazyEnd[2*i] += lazyEnd[i];
            
            lazyStart[2*i+1] += lazyEnd[i]*(mid+1-l)+lazyStart[i];
            lazyEnd[2*i+1] += lazyEnd[i];
        }
        lazyEnd[i] = 0;
        lazyStart[i] = 0;
    }
    if(y<l || x>r){
        return 0;
    }
    if(x<=l && r<=y){
        return tree[i];
    }

    long long a = query(2*i,l,mid,x,y,tree,lazyStart,lazyEnd);
    long long b =query(2*i+1,mid+1,r,x,y,tree,lazyStart,lazyEnd);
    
    return a+b;
}

int main(){

    long long n,q;
    cin>>n>>q;

    long long t[n+1];
    for (long long i = 1; i <= n; i++)
    {
        cin>>t[i];
    }

    long long tree[3*(n+1)]={0},lazyStart[3*(n+1)]={0},lazyEnd[3*(n+1)]={0};    
    build(1,1,n,t,tree);

    for (long long i = 1; i <=q; i++)
    {
        long long q1,a,b;
        cin>>q1>>a>>b;

        if(q1==1){
            update(1,1,n,a,b,t,tree,lazyStart,lazyEnd);
        }
        else{
            cout<<query(1,1,n,a,b,tree,lazyStart,lazyEnd)<<"\n";
        }
    }
    
    return 0;
}

// 2 2 3 4 5
// 3 4 6 4 5
// 3 4 7 6 8
// 3 5 9 9 8
// 4 7 9 9 8   
// 1 2 3 4 5  6  7  8  9  10
// 1 3 5 7 9  11 7  8  9  10
// 1 3 5 8 11 14 11 13 15 10