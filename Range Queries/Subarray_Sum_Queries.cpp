#include <bits/stdc++.h>
using namespace std;
 //tree 0 sum
 //tree 1 range max
 //lrtree 0 left sum
//lrtree 1 right sum
void updateTree(long long i,long long l,long long r,long long k,long long val,long long x[],vector <vector <long long>>  &tree,vector <vector <long long>>  &lrtree){
    if(l==r){
        x[l] = val;
        lrtree[0][i] = x[l];
        lrtree[1][i] = x[l];
        tree[0][i] = x[l];
        tree[1][i] = x[l];
        return;
    }
    long long mid = (l+r)>>1;
    if(k<=mid){
        updateTree(2*i,l,mid,k,val,x,tree,lrtree);
    }
    else{
        updateTree(2*i+1,mid+1,r,k,val,x,tree,lrtree);
    }
    tree[0][i] = tree[0][2*i] + tree[0][2*i+1];
    lrtree[0][i] = max(lrtree[0][2*i],tree[0][2*i]+ lrtree[0][2*i+1]);
    lrtree[1][i] = max(lrtree[1][2*i+1],tree[0][2*i+1]+ lrtree[1][2*i]);
    tree[1][i] = max(tree[1][2*i],tree[1][2*i+1]);
    tree[1][i] = max(tree[1][i],lrtree[1][2*i]+lrtree[0][2*i+1]);
    // cout<<"L : "<<l<<" r : "<<r<<" max "<<tree[1][i]<<" L sum :"<<lrtree[0][i]<<" R sum :"<<lrtree[1][i]<<endl;
}

int main(){
    long long n,m;
    cin>>n>>m;

    long long x[n+1]={0};
    vector <vector <long long>> tree(3,vector <long long>(3*(n+1),0));
    vector <vector <long long>> lrtree(3,vector <long long>(3*(n+1),0));

    for(long long i=1 ;i<=n;++i){
        cin>>x[i];
        updateTree(1,1,n,i,x[i],x,tree,lrtree);
    }

    for (int i = 0; i < m; i++)
    {
        long long k ,val;
        cin>>k>>val;
        updateTree(1,1,n,k,val,x,tree,lrtree);
        if(tree[1][1]>0){
            cout<<tree[1][1]<<"\n";
        }
        else{
            cout<<"0 \n";
        }
    }
    
    return 0;
}