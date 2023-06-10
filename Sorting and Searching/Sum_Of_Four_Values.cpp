#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, target;
    cin >> n >> target;
    vector<pair<long long, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        arr[i] = {x, i + 1};
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 3; i++)
    {
        if (i == 0 || arr[i].first != arr[i - 1].first)
        {
            // cout<<arr[i]<<endl;
            for (int l = i + 1; l < n - 2; l++)
            {
                if (l == i + 1 || arr[l].first != arr[l - 1].first)
                {
                    long long sum = arr[i].first+arr[l].first;
                    int j = l + 1;
                    int k = n - 1;
                    while (j < k)
                    {
                        if (sum + arr[j].first + arr[k].first == target)
                        {
                            cout << arr[i].second << " " << arr[j].second << " " << arr[k].second<<" "<<arr[l].second << endl;
                            return 0;
                        }
                        else if (sum + arr[j].first + arr[k].first < target)
                        {
                            while (j < k && arr[j + 1].first == arr[j].first)
                                j++;
                            j++;
                        }
                        else
                        {
                            while (j < k && arr[k - 1].first == arr[k].first)
                                k--;
                            k--;
                        }
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}