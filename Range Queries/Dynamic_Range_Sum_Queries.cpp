 #include <bits/stdc++.h>
using namespace std;

void Build_Segment_Tree(int i,int start,int end,long long a[],long long tree[]) {
    if(start == end){
        tree[i] = a[start];
        return;
    }
    int mid = (start + end)/2;
    Build_Segment_Tree(2*i+1,start,mid,a,tree);
    Build_Segment_Tree(2*i+2,mid+1,end,a,tree);
    tree[i] = tree[2*i+1]+tree[2*i+2];
}

long long Answer_From_Segment_tree(int i,int start,int end ,long long a[],long long tree[],int t1,int t2){
    if(start > t2 || end < t1){
        return 0;
    }
    if(start >= t1 && end <= t2){
        return tree[i];
    }
    int mid = (start+end)/2;
    long long left = Answer_From_Segment_tree(2*i+1,start,mid,a,tree,t1,t2);
    long long right = Answer_From_Segment_tree(2*i+2,mid+1,end,a,tree,t1,t2);
    return left+right;
}

void update_tree(int i,int start,int end,long long a[],long long tree[],long long diff,int index){
    tree[i] = tree[i]-diff;
    if(start==end){
        return;
    }
    int mid = (start+end)/2;
    if(index<=mid){
        update_tree(2*i+1,start,mid,a,tree,diff,index);
    }
    else{
        update_tree(2*i+2,mid+1,end,a,tree,diff,index);
    }
}

 
int main(){
    int test,cases=0;
    int n;
    cin>>n;
    cin>>test;

    long long a[n],tree[3*n]={0};
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }

    Build_Segment_Tree(0,0,n-1,a,tree);

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<tree[i]<<" ";
    // }
    // cout<<endl;
    
    while(test){
        test--;
        cases++;
        long long k,t1,t2;
        cin>>k>>t1>>t2;
        if(k==1){
            t1--;
            long long diff = a[t1] - t2;
            a[t1] = t2;
            // cout<<"gone to update \n";
            update_tree(0,0,n-1,a,tree,diff,t1);
        }
        else{
            t1--;
            t2--;
            cout<<Answer_From_Segment_tree(0,0,n-1,a,tree,t1,t2)<<endl;
        }

    }
    return 0;
}