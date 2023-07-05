#include <bits/stdc++.h>
using namespace std;

void update(int i, int l, int r, int target, int tree[])
{
    if (l == r)
    {
        // p[i]+=1;
        tree[i] += 1;
        return;
    }

    int mid = (l + r) >> 1;
    if (target <= mid)
    {
        update(2 * i, l, mid, target, tree);
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    else
    {
        update(2 * i + 1, mid + 1, r, target, tree);
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}

int get_sum(int i, int l, int r, int p, int q, int tree[])
{
    if (p <= l && r <= q)
    {
        return tree[i];
    }
    else if (q < l || p > r)
    {
        return 0;
    }
    int mid = (l + r) >> 1;
    return get_sum(2 * i, l, mid, p, q, tree) + get_sum(2 * i + 1, mid + 1, r, p, q, tree);
}

int main()
{
    int n;
    cin >> n;
    int x[n + 1], p[n + 1];
    int tree[(3ll) * n] = {0};

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++)
    {
        // cout<<x[p[i]+get_sum(1,1,n,1,p[i],tree)]<<" ";
        // update(1,1,n,p[i],tree);
        int l = 1;
        int r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            int tempSum = get_sum(1, 1, n, 1, mid, tree);
            if (mid - tempSum == p[i])
            {
                r = mid;
            }
            else if (mid - tempSum > p[i])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        // cout<<"r : "<<r<<endl;
        cout << x[r] << " ";
        update(1,1,n,r,tree);
    }

    return 0;
}