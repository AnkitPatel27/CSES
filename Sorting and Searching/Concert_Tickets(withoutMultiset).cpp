#include <bits/stdc++.h>
using namespace std;

int binary_searchs(int target, int a[], int vis[], int n)
{
    int  l = 0 ,r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] <= target)
            l = mid + 1;
        else
            r = mid - 1;
        
    }
    return l - 1;
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    int ticket[n],people[m], vis[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ticket[i];
        vis[i] = -1;
    }
    
    for (int i = 0; i < m; i++)
    {
        cin>>people[i];
    }
    
    
    sort(ticket, ticket + n);

    for (int i = 0; i < m; i++)
    {
        int k =people[i];
        int index = binary_searchs(k, ticket, vis, n);
        int cur = index;
        while (index > 0 && vis[index] >= 0)
        {
            index = vis[index];
            index--;
        }
        if (index == -1 || vis[index] >= 0)
        {
            cout << -1 << "\n";
            continue;
        }
        vis[index] = index;
        vis[cur] = index;
        cout << ticket[index] << "\n";
    }

    return 0;
}