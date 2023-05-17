#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    multiset<int> ticket;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        ticket.insert(temp);
    }
    
    for (int i = 0; i < m; i++)
    {
        int k;
        cin>>k;
        auto it = ticket.upper_bound(k);
        if(it==ticket.begin()){
            cout<<-1<<endl;
        }
        else{
            it--;
            cout<<*it<<endl;
            ticket.erase(it);
        }
    }

    return 0;
}