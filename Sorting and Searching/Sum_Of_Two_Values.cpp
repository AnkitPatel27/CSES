#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // unordered_map<int,int>mt;
    // for (int i = 0; i < n; i++)
    // {
    //     if(mt.find(x - a[i])!=mt.end()){
    //         cout<<mt[x-a[i]]+1<<" "<<i+1;
    //         return 0;
    //     }
    //     else{
    //         mt[a[i]] = i;
    //     }
    // }
    // cout<<"IMPOSSIBLE";

    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] + a[j] == x)
        {
            cout << i + 1 << " " << j + 1;
            return 0;
        }
        else if (a[i] + a[j] < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}