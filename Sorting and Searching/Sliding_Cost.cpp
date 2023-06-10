#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
  
void insert(multiset <long long> &left,multiset <long long> &right,long long k,long long &lsum,long long &rsum){
    if((left.size()==0 && right.size()==0 )|| *right.begin()>=k){
        // cout<<"ins\n";
        left.insert(k);
        lsum+=k;
        if(left.size()>right.size()){
            auto last = left.end();
            last--;
            right.insert(*last);
            rsum+=*last;
            lsum-=*last;
            left.erase(last);
        }
        
    }
    else{
        right.insert(k);
        rsum+=k;
        if(left.size()<right.size()){
            left.insert(*right.begin());
            lsum+=*right.begin();
            rsum-=*right.begin();
            right.erase(right.begin());
        }
    }
}

void erase(multiset <long long> &left,multiset <long long> &right,long long k,long long &lsum,long long &rsum){
    if(left.find(k)!=left.end()){
        left.erase(left.find(k));
        lsum-=k;
        if(left.size()<right.size()){
            lsum+=*right.begin();
            rsum-=*right.begin();
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }
    else{
        right.erase(right.find(k));
        rsum-=k;
        if(left.size()>right.size()){
            auto last = left.end();
            last--;
            rsum+=*last;
            lsum-=*last;
            right.insert(*last);
            left.erase(last);
        }
    }
}

int main(){
    long long n,k;
    cin>>n>>k;
    long long x[n];
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
    }

    multiset <long long> left,right;
    long long lsum =0,rsum=0;
    for (int i = 0; i < k-1; i++)
    {
        insert(left,right,x[i],lsum,rsum);
    }
    if(k%2==1){
        for (int i = k-1; i < n; i++)
        {
            insert(left,right,x[i],lsum,rsum);
            long long median = (right.size()>left.size())?*right.begin():*left.rbegin();
            long long llen = left.size();
            long long ans = abs(median*llen-lsum) +abs(rsum - (k-llen)*median);
            cout<<ans<<" ";
            erase(left,right,x[i-k+1],lsum,rsum);

        }
    }
    else{
        for (int i = k-1; i < n; i++)
        {
            insert(left,right,x[i],lsum,rsum);
            long long median = (*right.begin()+*left.rbegin())>>1;
            long long llen = left.size();
            long long ans = abs(median*llen-lsum) +abs(rsum - (k-llen)*median);
            // cout<<lsum<<" "<<rsum<<endl;
            cout<<ans<<" ";
            erase(left,right,x[i-k+1],lsum,rsum);
        }
    }
    
    return 0;
}

