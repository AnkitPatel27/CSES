#include <bits/stdc++.h>
using namespace std;
 
void Build_Minimum_Segment_tree(int i,int start,int end,int a[],int tree[]){
    if(start==end){
        tree[i]=a[start];
        return;
    }
    int mid=(start+end)/2;
    Build_Minimum_Segment_tree(2*i+1,start,mid,a,tree);
    Build_Minimum_Segment_tree(2*i+2,mid+1,end,a,tree);
    tree[i]=min(tree[2*i+1],tree[2*i+2]);
}

int Query_Minimum_Segment_tree(int i,int start,int end,int x,int y,int tree[]){
    if(start>y || end<x){
        return INT_MAX;
    }
    if(start>=x && end<=y){
        return tree[i];
    }
    int mid=(start+end)/2;
    int left=Query_Minimum_Segment_tree(2*i+1,start,mid,x,y,tree);
    int right=Query_Minimum_Segment_tree(2*i+2,mid+1,end,x,y,tree);
    return min(left,right);
}

void Update_Segment_Tree(int i, int start,int end ,int index , int updateVal , int tree[]){
    if(start==end){
        tree[i]=updateVal;
        return;
    }
    int mid = (start + end)/2;
    if(index<=mid){
        Update_Segment_Tree(2*i+1,start,mid,index,updateVal,tree);
    }
    else
        Update_Segment_Tree(2*i+2,mid+1,end,index,updateVal,tree);
    
    tree[i] = min(tree[2*i+1],tree[2*i+2]);
}

int main(){
    int test,cases=0,n;
    cin>>n;
    cin>>test;
    int a[n],tree[3*n]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    Build_Minimum_Segment_tree(0,0,n-1,a,tree);

    while(test){
        test--;
        cases++;
        int k,t1,t2;
        cin>>k;
        cin>>t1;
        cin>>t2;
        if(k==1){
            t1--;
            a[t1] = t2;
            Update_Segment_Tree(0,0,n-1,t1,t2,tree);
        }
        else{
            t1--;
            t2--;
            cout<<Query_Minimum_Segment_tree(0,0,n-1,t1,t2,tree)<<endl;
        }
    }
    return 0;
}