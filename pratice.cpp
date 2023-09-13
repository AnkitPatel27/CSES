#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)
 
void build(int index,int l, int r,vl &a,vl &seg){
    if(l==r){
        seg[index] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(2*index,l,mid,a,seg);
    build(2*index+1,mid+1,r,a,seg);
    seg[index] = seg[2*index]+seg[2*index+1]; 
}

void Update(int index,int l,int r,int x,int y,ll val,vl &a,vl &seg,vl &lazy){
    
    if(y<l || r<x){
        return ;
    }

    if(l==r){
        seg[index] += val+lazy[index];
        lazy[index] = 0;
        // cout<<l<<" "<<r<<endl;
        // cout<<seg[index]<<endl;
        return;
    }

    if(lazy[index]!=0){
        lazy[2*index]+=lazy[index];
        lazy[2*index+1]+=lazy[index];
        seg[index]+=(lazy[index]*((r-l)+1));
        lazy[index]=0;
    }

    if(x<=l && r<=y){
        lazy[index]+=val;
        return;
    }

    int mid = (l+r)>>1;

    Update(2*index,l,mid,x,y,val,a,seg,lazy);
    Update(2*index+1,mid+1,r,x,y,val,a,seg,lazy);

}

ll query(int index,int l,int r,int x,int y,vl &a,vl &seg,vl &lazy){
    
    if(y<l || r<x){
        return 0;
    }

    if(l==r){
        // cout<<l<<" "<<r<<endl;
        // cout<<lazy[index]<<endl;
        seg[index] += lazy[index];
        lazy[index] = 0;
        return seg[index];
    }

    if(l!=r && lazy[index]!=0){
        lazy[2*index]+=lazy[index];
        lazy[2*index+1]+=lazy[index];
        seg[index]+=(lazy[index]*((r-l)+1));
        lazy[index]=0;
    }

    if(x<=l && r<=y){
        // lazy[index]+= val;
        return seg[index];
    }

    int mid = (l+r)>>1;

    ll left  = query(2*index,l,mid,x,y,a,seg,lazy);
    ll right = query(2*index+1,mid+1,r,x,y,a,seg,lazy);

    return (left+right);
}


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;

    vl a(n+1,0),seg(4*n+1),lazy(4*n+1);
    
    FOR(1,n,1){
        cin>>a[i];
    }

    build(1,1,n,a,seg);

    FOR(1,m,1){
        int q;
        cin>>q;
        if(q==1){
            int a1,b1,u;
            cin>>a1>>b1>>u;
            Update(1,1,n,a1,b1,u,a,seg,lazy);
        }
        else if(q==2){
            int k;
            cin>>k;
            cout<<query(1,1,n,k,k,a,seg,lazy)<<endl;
        }
    }




    
    return 0;
}

// 8 3
// 3 2 4 5 1 1 5 3
// 2 4
// 1 2 5 1
// 2 4

// 8 900
// 7 6 4 6 2 9 4 8
// 1 8 8 10
// 2 1
// 2 2