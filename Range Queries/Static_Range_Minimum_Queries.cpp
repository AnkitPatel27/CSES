#include <bits/stdc++.h>
using namespace std;
 
void Build_Segment_Tree(int i,int start,int end,int tree[],int a[]){
    if(start == end){
        tree[i] = a[start];
        return;
    }
    int mid = (start + end)/2;
    Build_Segment_Tree(2*i+1,start,mid,tree,a);
    Build_Segment_Tree(2*i+2,mid+1,end,tree,a);
    tree[i] = min(tree[2*i+1],tree[2*i+2]);
}

int answer (int i ,int start,int end ,int tree[],int a[],int t1,int t2) {
    if(t1<=start && t2>=end){
        // cout<<" i : "<<i<<endl;
        return tree[i];
    }
    if(t1>end || t2<start){
        return INT_MAX;
    }
    int mid = (start + end)/2;
    return min(answer(2*i+1,start,mid,tree,a,t1,t2),answer(2*i+2,mid+1,end,tree,a,t1,t2));
}

int main(){
    int n,test,cases=0;
    cin>>n;
    cin>>test;
    int a[n],tree[3*n]={INT_MAX};
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }


    Build_Segment_Tree(0,0,n-1,tree,a);
    // for (int i = 0; i < 3*n; i++)
    // {
    //     cout<<tree[i]<<" ";
    // }
    // cout<<endl;

    while(test){
        test--;
        cases++;
        int t1,t2;
        cin>>t1>>t2;
        cout<<answer(0,0,n-1,tree,a,t1-1,t2-1)<<endl;
    }
    return 0;
}