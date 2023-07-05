#include <bits/stdc++.h>
using namespace std;
 
void createTree(long long i,long long l,long long r,long long p[],long long tree[],int isPlus){
    if(l==r){
        if(isPlus==1){
            tree[i] = p[l]+l;
        }
        else{
            tree[i] = p[l]-l;
        }
        return;
    }
    
    long long mid = (l+r)>>1;
    createTree(2*i,l,mid,p,tree,isPlus);
    createTree(2*i+1,mid+1,r,p,tree,isPlus);
    tree[i] = min(tree[2*i] , tree[2*i+1]);
}

long long query(long long i,long long l,long long r,long long x,long long y,long long tree[]){
    if(x>r || y<l )
        return LONG_LONG_MAX;
    
    if(x<=l && r<=y){
        return tree[i];
    }
    long long mid = (l+r)>>1;
    // cout<<"l : "<<l<<"r : "<<r<<endl;
    return min(query(2*i,l,mid,x,y,tree),query(2*i+1,mid+1,r,x,y,tree));
}

void update(long long i,long long l,long long r,long long k,long long val,long long p[],long long tree[],int isPlus){
    if(l==r){
        p[l] = val;
        if(isPlus==1){
            tree[i] = p[l]+l;
        }
        else{
            tree[i] = p[l]-l;
        }
        return;
    }
    long long mid = (l+r)>>1;
    if(k<=mid){
        update(2*i,l,mid,k,val,p,tree,isPlus);
    }
    else{
        update(2*i+1,mid+1,r,k,val,p,tree,isPlus);
    }

     tree[i] = min(tree[2*i] , tree[2*i+1]);
    
}

int main(){
    long long n,q;
    cin>>n>>q;

    long long p[n+1],plustree[3*(n+1)]={0},minustree[3*(n+1)]={0};
    for (int i = 1; i <= n; i++)
    {
        cin>>p[i];
    }

    createTree(1,1,n,p,plustree,1);
    createTree(1,1,n,p,minustree,0);
    for (int i = 0; i < q; i++)
    {
        long long qu;
        cin>>qu;
        if(qu==1){
            long long k,val;
            cin>>k>>val;
            update(1,1,n,k,val,p,plustree,1);
            update(1,1,n,k,val,p,minustree,0);
        }
        else{
            long long k;
            cin>>k;
            if(k==1){
                long long ans = plustree[1]-k;
                cout<<ans<<endl;
            }
            else if(k==n){
                long long ans = minustree[1]+k;
                cout<<ans<<endl;
            }
            else{
                // cout<<"came:"<<k<<" \n";
                long long back = query(1,1,n,1,k,minustree)+k;
                // cout<<"came2: \n";
                long long front = query(1,1,n,k,n,plustree)-k;
                cout<<min(back,front)<<endl;
            }
        }
    }
    
    
    return 0;
}