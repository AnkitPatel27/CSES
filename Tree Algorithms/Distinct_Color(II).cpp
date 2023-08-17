#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)

const int N = (int)2e5+1; // Define N as a constant for array sizes

vi color(N);
vi start(N), endt(N), a(N), lastColor(N, 0);
vvi adj(N);
int timer = 1;

void updateFen(int index, int newVal, int n) {
    if(index <= 0 || index > n) { // Check if index is out of bounds
        return;
    }
    for(int i = index; i <= n; i += (i & (-i))) {
        a[i] += newVal;
    }
}

int queryFen(int index) {
    if(index <= 0) {
        return 0;
    }

    ll res = 0;
    for(int i = index; i > 0; i -= (i & (-i))) {
        res += a[i];
    }

    return res;
}

void dfs(int node, int par) {
    start[node] = timer++;

    for(int nxt : adj[node]) {
        if(nxt != par) {
            dfs(nxt, node);
        }
    }

    endt[node] = timer-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    FOR(1, n, 1) {
        cin >> color[i];
    }

    FOR(1, n - 1, 1) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 1);
    vector<vector<pair<int,int>>> query(N);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<start[i]<<" ";
    // }
    // cout<<endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<endt[i]<<" ";
    // }
    // cout<<endl;

    for(int i = 1; i <= n; i++) {
        query[endt[i]].push_back({start[i], i});
    }

    

    map<int, int> mp;
    
    vi ans(N, 0);
    vi scolors(N,0);    

    for (int i = 1; i <=n; i++)
    {
        scolors[start[i]] = color[i]; 
        // cout<<scolors[i]<<" ";
    }
    // for (int i = 1; i <=n; i++)
    // {
    //     // scolors[start[i]] = color[i]; 
    //     cout<<scolors[i]<<" ";
    // }
    // cout<<endl;


    

    for(int i = 1; i <= n; i++) {

        if(mp.count(scolors[i]) > 0) {
            updateFen(mp[scolors[i]], -1, n);
        }

        mp[scolors[i]] = i; // Store the most recent index of color
        updateFen(i, 1, n);

        for(int j = 0; j < query[i].size(); j++) {
            int start1 = query[i][j].first;
            int end1 = i;
            int index = query[i][j].second;

            ans[index] = queryFen(end1) - queryFen(start1 - 1);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
