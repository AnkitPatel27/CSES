#include <bits/stdc++.h>
using namespace std;

void ptreeCreate(long long i, long long l, long long r, long long x[], long long ptree[])
{
    if (l == r)
    {
        ptree[i] = x[l];
        return;
    }
    long long mid = (l + r) / (2ll);
    ptreeCreate(2 * i + 1, l, mid, x, ptree);
    ptreeCreate(2 * i + 2, mid + 1, r, x, ptree);
    ptree[i] = max(ptree[2 * i + 1], ptree[2 * i + 2]);
}

void prefixtree(long long i, long long l, long long r, long long x[], long long ptree[])
{
    if (l == r)
    {
        ptree[i] = x[l];
        return;
    }
    long long mid = (l + r) / (2ll);
    prefixtree(2 * i + 1, l, mid, x, ptree);
    prefixtree(2 * i + 2, mid + 1, r, x, ptree);
    ptree[i] = ptree[2 * i + 1] + ptree[2 * i + 2];
}

void ptreeUpdate(long long i, long long l, long long r, long long a, long long b, long long k, long long x[], long long ptree[], long long lazyLoad[])
{
    long long mid = (l + r) >> 1;
    ptree[i] = ptree[i] + lazyLoad[i];
    if (l != r)
    {
        lazyLoad[2 * i + 1] += lazyLoad[i];
        lazyLoad[2 * i + 2] += lazyLoad[i];
    }
    lazyLoad[i] = 0;

    if (a > r || b < l)
    {
        return;
    }
    if (a <= l && r <= b)
    {
        // cout<<"l :"<<l<<" r : "<<r<<" a :"<<a<<" b : "<<b<<"ansOLD :"<<ptree[i]<<endl;
        ptree[i] = ptree[i] + k;
        if (l != r)
        {
            lazyLoad[2 * i + 1] += lazyLoad[i] + k;
            lazyLoad[2 * i + 2] += lazyLoad[i] + k;
        }
        lazyLoad[i] = 0;
        return;
    }

    ptreeUpdate(2 * i + 1, l, mid, a, b, k, x, ptree, lazyLoad);
    ptreeUpdate(2 * i + 2, mid + 1, r, a, b, k, x, ptree, lazyLoad);
    ptree[i] = max(ptree[2 * i + 1], ptree[2 * i + 2]);
    // cout<<"l :"<<l<<" r : "<<r<<" a :"<<a<<" b : "<<b<<"ans :"<<ptree[i]<<endl;
}

void prefixUpdate(long long i, long long l, long long r, long long index, long long k, long long x[], long long ptree[])
{
    long long mid = (l + r) >> 1;
    if (l == r)
    {
        ptree[i] = ptree[i] + k;
        return;
    }
    if (index <= mid)
    {
        prefixUpdate(2 * i + 1, l, mid, index, k, x, ptree);
    }
    else
    {
        prefixUpdate(2 * i + 2, mid + 1, r, index, k, x, ptree);
    }
    ptree[i] = ptree[2 * i + 1] + ptree[2 * i + 2];
}

long long ptreequery(long long i, long long l, long long r, long long a, long long b, long long x[], long long ptree[], long long lazyLoad[])
{
    long long mid = (l + r) >> 1;
    ptree[i] = ptree[i] + lazyLoad[i];
    if (l != r)
    {
        lazyLoad[2 * i + 1] += lazyLoad[i];
        lazyLoad[2 * i + 2] += lazyLoad[i];
    }
    lazyLoad[i] = 0;
    if (a > r || b < l)
    {
        return LONG_LONG_MIN;
    }
    if (a <= l && r <= b)
    {
        return ptree[i];
    }
    long long x1 = ptreequery(2 * i + 1, l, mid, a, b, x, ptree, lazyLoad);
    long long x2 = ptreequery(2 * i + 2, mid + 1, r, a, b, x, ptree, lazyLoad);
    return max(x1, x2);
}

long long prefixquery(long long i, long long l, long long r, long long a, long long b, long long x[], long long ptree[])
{
    long long mid = (l + r) >> 1;
    if (a > r || b < l)
    {
        return 0ll;
    }

    if (a <= l && r <= b)
    {
        return ptree[i];
    }

    long long temp = prefixquery(2 * i + 1, l, mid, a, b, x, ptree) + prefixquery(2 * i + 2, mid + 1, r, a, b, x, ptree);
    return temp;
}

int main()
{
    long long n, q;
    cin >> n >> q;
    long long x[n], p[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    p[0] = x[0];
    for (int i = 1; i < n; i++)
    {
        p[i] = p[i - 1] + x[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<p[i]<<" ";
    // }

    long long ptree[3 * n];
    long long prefix[3 * n] = {0};
    long long lazyLoad[3 * n] = {0};
    prefixtree(0, 0, n - 1, x, prefix);
    ptreeCreate(0, 0, n - 1, p, ptree);
    for (int i = 0; i < q; i++)
    {
        long long t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
        {
            long long k = b - x[a - 1];
            x[a - 1] = b;
            // cout<<"upd : "<<k<<endl;
            prefixUpdate(0, 0, n - 1, a - 1, k, x, prefix);
            ptreeUpdate(0, 0, n - 1, a - 1, n - 1, k, p, ptree, lazyLoad);
        }
        else
        {
            if (a - 1 == 0)
            {
                long long ans = ptreequery(0, 0, n - 1, a - 1, b - 1, p, ptree, lazyLoad);
                if (ans < 0)
                {
                    cout << 0 << endl;
                }
                else
                {
                    cout << ans << endl;
                }
            }
            else
            {
                long long ans = ptreequery(0, 0, n - 1, a - 1, b - 1, p, ptree, lazyLoad) - prefixquery(0, 0, n - 1, 0, a - 2, x, prefix);
                if (ans < 0)
                {
                    cout << 0 << endl;
                }
                else
                {
                    cout << ans << endl;
                }
            }
        }
    }

    return 0;
}