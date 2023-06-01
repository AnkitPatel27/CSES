#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test, cases = 0, n;
    cin >> n;
    cin >> test;

    char a[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int prefix[n][n], prefPrefixSum[n][n];
    for (int i = 0; i < n; i++)
    {
        int curSum = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '*')
            {
                curSum++;
            }
            prefix[i][j] = curSum;
            // cout<<prefix[i][j]<<" ";
        }
        // cout<<endl;
    }
    // cout<<endl;
    for (int i = 0; i < n; i++)
    {
        int curSum = 0;
        for (int j = 0; j < n; j++)
        {
            curSum += prefix[j][i];
            prefPrefixSum[j][i] = curSum;
        }
    }

    

    while (test)
    {
        test--;
        cases++;
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1--;
        x1--;
        y2--;
        x2--;
        int ans = 0;
        ans+=prefPrefixSum[x2][y2];
        if(x1>0){
            ans-=prefPrefixSum[x1-1][y2];
        }
        if(y1>0){
            ans-=prefPrefixSum[x2][y1-1];
            if(x1>0){
                ans+=prefPrefixSum[x1-1][y1-1];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}