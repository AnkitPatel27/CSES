#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main(){
    int n;
    int k;
    cin>>n>>k;
    ordered_set s;

    for (int i = 0; i < n; i++)
    {
        s.insert(i+1);
    }
    
    int i = 0;
    int size = n;
    while(size>1){
        int index = (i+k)%size;
        auto p = s.find_by_order(index);
        cout<<*p<< " ";
        s.erase(p);
        size--;
        i = index;
    }
    cout << *(s.find_by_order(0)) 
         << endl;
    return 0;
}