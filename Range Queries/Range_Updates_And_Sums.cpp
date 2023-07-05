#include <bits/stdc++.h>
using namespace std;
 
void updateByX(long long i,long long l,long long r,long long a,long long b,long long val,long long t[],long long tree[],long long lazy[],long long point[],long long ispoint[]){
    
    if(point[i]!=0){
        tree[i] = point[i]*(r-l+1);
        if(l!=r){
            point[2*i] = point[i];
            point[2*i+1] = point[i];
            lazy[2*i] = 0;
            lazy[2*i+1] = 0;
        }
        //  cout<<"POINT l : "<<l<<" r :"<<r<<" tree : "<<tree[i]<<" lazy : "<<point[i]<<endl;
        point[i] = 0;
    }
    
    if(lazy[i]!=0){
        tree[i] += lazy[i]*(r-l+1);
        if(l!=r){
            lazy[2*i]+=lazy[i];
            lazy[2*i+1]+=lazy[i];
        }
        //  cout<<"lazy l : "<<l<<" r :"<<r<<" tree : "<<tree[i]<<" lazy : "<<lazy[i]<<endl;
        lazy[i] = 0;
    }
 
 
    if(a>r || b<l){
        return;
    }
 
    if(a<=l && r<=b){
        tree[i]+=val*(r-l+1);
        lazy[i] = 0;
        if(l!=r){
            lazy[2*i] += val; 
            lazy[2*i+1] += val;            
        }
        // cout<<"last l : "<<l<<" r :"<<r<<endl;
        // cout<<tree[i]<<endl;
        return;
    }
 
    long long mid = (l+r)>>1;
    // cout<<"l : "<<l<<" r :"<<r<<endl;
    updateByX(2*i,l,mid,a,b,val,t,tree,lazy,point,ispoint);
    updateByX(2*i+1,mid+1,r,a,b,val,t,tree,lazy,point,ispoint);
    tree[i] = tree[2*i]+tree[2*i+1];
}
 
void updatetoX(long long i,long long l,long long r,long long a,long long b,long long val,long long t[],long long tree[],long long lazy[],long long point[],long long ispoint[]){
    
    if(point[i]!=0){
        tree[i] = point[i]*(r-l+1);
        if(l!=r){
            point[2*i] = point[i];
            point[2*i+1] = point[i];
            lazy[2*i] = 0;
            lazy[2*i+1] = 0;
        }
        //  cout<<"POINT l : "<<l<<" r :"<<r<<" tree : "<<tree[i]<<" lazy : "<<point[i]<<endl;
        point[i] = 0;
    }
    
    if(lazy[i]!=0){
        tree[i] += lazy[i]*(r-l+1);
        if(l!=r){
            lazy[2*i]+=lazy[i];
            lazy[2*i+1]+=lazy[i];
        }
        //  cout<<"lazy l : "<<l<<" r :"<<r<<" tree : "<<tree[i]<<" lazy : "<<lazy[i]<<endl;
        lazy[i] = 0;
    }
 
    if(a>r || b<l){
        return;
    }
 
    if(a<=l && r<=b){
        tree[i] =val*(r-l+1);
        if(l!=r){
            point[2*i] = val; 
            ispoint[2*i] = 1; 
            point[2*i+1] = val; 
            ispoint[2*i+1] = 1; 
            lazy[2*i] = 0;
            lazy[2*i+1] = 0;
        }
        point[i] = 0;
        lazy[i] = 0;
        // cout<<"tree lazy l : "<<l<<" r :"<<r<<" tree : "<<tree[i]<<endl;
        // cout<<tree[i]<<endl;
        return;
    }
 
    long long mid = (l+r)>>1;
        // cout<<"l : "<<l<<" r :"<<r<<endl;
    updatetoX(2*i,l,mid,a,b,val,t,tree,lazy,point,ispoint);
    updatetoX(2*i+1,mid+1,r,a,b,val,t,tree,lazy,point,ispoint);
    tree[i] = tree[2*i]+tree[2*i+1];
}
 
long long query(long long i,long long l,long long r,long long a,long long b,long long tree[],long long lazy[],long long point[],long long ispoint[]){
    
    if(point[i]!=0){
        tree[i] = point[i]*(r-l+1);
        if(l!=r){
            point[2*i] = point[i];
            point[2*i+1] = point[i];
            lazy[2*i] = 0;
            lazy[2*i+1] = 0;
        }
        point[i] = 0;
    }
    
    if(lazy[i]!=0){
        tree[i] += lazy[i]*(r-l+1);
        if(l!=r){
            lazy[2*i]+=lazy[i];
            lazy[2*i+1]+=lazy[i];
        }
        lazy[i] = 0;
    }
 
    if(a>r || b<l){
        return 0;
    }
 
    if(a<=l && r<=b){
        return tree[i];
    }
 
    long long mid = (l+r)>>1;
    long long a1 = query(2*i,l,mid,a,b,tree,lazy,point,ispoint);
    long long b1 = query(2*i+1,mid+1,r,a,b,tree,lazy,point,ispoint);
    return a1+b1;
}
 
int main(){
    long long n,q;
    cin>>n>>q;
 
    long long t[n+1],tree[3*(n+1)]={0},lazy[3*(n+1)]={0},point[3*(n+1)]={0},isPoint[3*(n+1)]={0};
    for (int i = 0; i < n; i++)
    {
        cin>>t[i+1];
        updateByX(1,1,n,i+1,i+1,t[i+1],t,tree,lazy,point,isPoint);
    }
 
    for (int i = 0; i < q; i++)
    {
        long long type;
        cin>>type;
        if(type==1){
            long long a,b,x;
            cin>>a>>b>>x;
            updateByX(1,1,n,a,b,x,t,tree,lazy,point,isPoint);
        }
        else if(type==2){
            long long a,b,x;
            cin>>a>>b>>x;
            updatetoX(1,1,n,a,b,x,t,tree,lazy,point,isPoint);
        }
        else{
            long long a,b;
            cin>>a>>b;
            cout<<query(1,1,n,a,b,tree,lazy,point,isPoint)<<endl;
        }
    }
    
    
 
    return 0;
}