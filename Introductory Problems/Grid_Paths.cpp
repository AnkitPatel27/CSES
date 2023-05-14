#include <bits/stdc++.h>
using namespace std;

bool vis[8][8];

int dp(int x, int y, int i, string &s)
{
    if (i == 48 || x == 6 && y == 0)
    {
        if (i == 48 && x == 6 && y == 0)
            return 1;
        return 0;
    }

    if ((x + 1 > 6 || vis[x + 1][y]) && (x - 1 < 0 || vis[x - 1][y]))
        if (y - 1 >= 0 && y + 1 <= 6 && !vis[x][y + 1] && !vis[x][y - 1])
            return 0;
    if ((y + 1 > 6 || vis[x][y + 1]) && (y - 1 < 0 || vis[x][y - 1]))
        if (x - 1 >= 0 && x + 1 <= 6 && !vis[x + 1][y] && !vis[x - 1][y])
            return 0;

    int ans = 0;
    vis[x][y] = true;
    if (s[i] == '?' || s[i] == 'D')
    {
        if (x < 6 && vis[x + 1][y] == false)
        {
            ans += dp(x + 1, y, i + 1, s);
        }
    }
    if (s[i] == '?' || s[i] == 'L')
    {
        if (y > 0 && vis[x][y - 1] == false)
        {
            ans += dp(x, y - 1, i + 1, s);
        }
    }
    if (s[i] == '?' || s[i] == 'R')
    {
        if (y < 6 && vis[x][y + 1] == false)
        {
            ans += dp(x, y + 1, i + 1, s);
        }
    }
    if (s[i] == '?' || s[i] == 'U')
    {
        if (x > 0 && vis[x - 1][y] == false)
        {
            ans += dp(x - 1, y, i + 1, s);
        }
    }
    vis[x][y] = false;
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int n = 48;
    int k = dp(0, 0, 0, s);
    cout << k << endl;
    return 0;
}