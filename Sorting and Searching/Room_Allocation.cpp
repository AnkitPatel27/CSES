#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, pair<int,int>>> a(n);
    vector<int> b(n);
    
    
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].first = x;
        a[i].second.first = y;
        a[i].second.second = i;
    }

    sort(a.begin(),a.end());

    int ans[n];
    int k = 2;

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(-1*a[0].second.first,1));
    ans[a[0].second.second] = 1;
    for (int i = 1; i < n; i++)
    {
        int minTime = -1*pq.top().first;
        int minVal = pq.top().second;
        if(a[i].first>minTime){
            pq.pop();
            pq.push(make_pair(-1*a[i].second.first,minVal));
            ans[a[i].second.second] = minVal;
        }
        else{
            pq.push(make_pair(-1*a[i].second.first,k));
            ans[a[i].second.second] = k;
            k++;
        }
    }

    cout<<k-1<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    

    return 0;
}

// 10
// 8 8 4
// 5 8 3
// 8 9 5
// 1 4 1
// 1 3 2
// 5 7 4
// 4 8 2
// 2 2 3
// 4 5 3
// 6 8 4