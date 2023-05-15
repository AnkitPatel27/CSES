#include <bits/stdc++.h>
using namespace std;

void Build_Segment_Tree(int i, int start, int end, long long a[], long long tree[])
{
    if (start == end)
    {
        tree[i] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    Build_Segment_Tree(2 * i + 1, start, mid, a, tree);
    Build_Segment_Tree(2 * i + 2, mid + 1, end, a, tree);
    tree[i] = 0;
}

void Update_Segment_Tree(int i, int start, int end, int updateVal, int x, int y, long long a[], long long tree[])
{
    if (start >= x && y >= end)
    {
        tree[i] += updateVal;
        return;
    }
    if (start > y || end < x)
    {
        return;
    }
    int mid = (start + end) / 2;
    Update_Segment_Tree(2 * i + 1, start, mid, updateVal, x, y, a, tree);
    Update_Segment_Tree(2 * i + 2, mid + 1, end, updateVal, x, y, a, tree);
}

long long Query_Segment_Tree(int i, int start, int end, int index, long long tree[]) 
{
    if (start >= index && end <= index)
    {
        return tree[i];
    }
    if (start > index || end < index)
    {
        return 0;
    }
    int mid = (start + end) / 2;
    long long left = Query_Segment_Tree(2 * i + 1, start, mid, index, tree);
    long long right = Query_Segment_Tree(2 * i + 2, mid + 1, end, index, tree);
    return left + right + tree[i];
}

int main()
{
    int test, cases = 0;
    int n;
    cin >> n;
    cin >> test;

    long long a[n], tree[3 * n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Build_Segment_Tree(0, 0, n - 1, a, tree);

    while (test)
    {
        test--;
        cases++;
        int k;
        cin >> k;
        if (k == 1)
        {
            long long t1, t2, u;
            cin >> t1 >> t2 >> u;
            Update_Segment_Tree(0, 0, n - 1, u, t1 - 1, t2 - 1, a, tree);
            // for (int i = 0; i < 3 * n; i++)
            // {
            //     cout << tree[i] << " ";
            // }
            // cout << endl;
        }
        else
        {
            int t1;
            cin >> t1;
            t1--;
            cout << Query_Segment_Tree(0, 0, n - 1, t1, tree) << endl;
        }
    }
    return 0;
}