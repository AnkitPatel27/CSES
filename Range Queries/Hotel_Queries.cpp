#include <bits/stdc++.h>
using namespace std;

void Build_Segment_Tree(int i, int start, int end, long long hotel[], long long tree[])
{
    if (start == end)
    {
        tree[i] = hotel[start];
        return;
    }
    int mid = (start + end) / 2;
    Build_Segment_Tree(2 * i + 1, start, mid, hotel, tree);
    Build_Segment_Tree(2 * i + 2, mid + 1, end, hotel, tree);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

long long Query(int i, int start, int end, long long hotel[], long long tree[], long long room_req)
{
    if (start == end && tree[i] >= room_req)
    {
        tree[i] = tree[i] - room_req;
        return start + 1;
    }
    int mid = (start + end) / 2;

    if (tree[i] < room_req)
    {
        return 0;
    }

    if (tree[2 * i + 1] >= room_req)
    {
        long long ans = Query(2 * i + 1, start, mid, hotel, tree, room_req);
        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
        return ans;
    }
    else
    {
        long long ans = Query(2 * i + 2, mid + 1, end, hotel, tree, room_req);
        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
        return ans;
    }
}

int main()
{
    int n, test;
    cin >> n >> test;

    long long hotel[n], tree[3 * n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> hotel[i];
    }

    Build_Segment_Tree(0, 0, n - 1, hotel, tree);

    while (test)
    {
        test--;
        int room_req;
        cin >> room_req;
        cout << Query(0, 0, n - 1, hotel, tree, room_req);
        if(test>0){
            cout<<" ";
        }
    }
    return 0;
}