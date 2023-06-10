#include <bits/stdc++.h>
using namespace std;

bool compar(pair<long long, long long> &a, pair<long long, long long> &b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> time(n);
    multiset<pair<long long, long long>> s;
    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        time[i].first = x;
        time[i].second = y;
    }

    sort(time.begin(), time.end(), compar);
    s.insert({time[0].second, 1});
    for (int i = 1; i < n; i++)
    {
        auto it = s.upper_bound({time[i].first, 0});
        if (it == s.begin() )
        {
            if((*it).first==time[i].first)
            {
                long long tempVal = (*it).second;
                s.erase(it);
                s.insert({time[i].second,tempVal+1});
                continue;
            }
            if(s.size()<k)
                s.insert({time[i].second, 1});
        }
        else
        {
            it--;
            long long tempVal = (*it).second;
            s.erase(it);
            s.insert({time[i].second, tempVal + 1});
        }
    }

    vector<long long> sw(s.size());
    long long i = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        sw[i] = (*it).second;
        // cout << (*it).first << "-" << sw[i] << endl;
        i++;
    }
    sort(sw.begin(), sw.end());
    long long ssize = s.size();
    long long sum = 0;
    for (long long t = 1; t <= k && ssize - t >= 0; t++)
    {
        sum += sw[ssize - t];
    }

    cout << sum << endl;
    return 0;
}