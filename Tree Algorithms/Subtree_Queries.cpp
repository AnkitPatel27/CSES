#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define FOR(start, end, step) for (int i = start; i <= end; i += step)

vvi adj((int)2e5+1);
vl w((int)2e5+1), start_time((int)2e5+1), end_time((int)2e5+1), a((int)2e5+1, 0),org((int)2e5+1,0);

int timer = 1;

void UpdateFenwick(int index, ll newVal, int n) {
    // ll k = newVal;
    // newVal = newVal - org[index];
    while (index <= n) {
        a[index] += newVal;
        index = index + (index & (-index));
    }

}

void buildFenwick(int n) {
    FOR(1, n, 1) {
        a[i] += org[i];
        int p = i + (i & (-i));
        if (p <= n) {
            a[p] += a[i];
        }
    }
}


ll QueryFenwick(int index) {
    ll ans = 0;
    while (index >= 1) {
        ans += a[index];
        index = index - (index & (-index));
    }
    return ans;
}

void dfs(int node, int par) {
    start_time[node] = timer++;
    for (int nxt : adj[node]) {
        if (nxt != par) {
            dfs(nxt, node);
        }
    }
    end_time[node] = timer - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int m;
    cin >> m;

    FOR(1, n, 1) {
        cin >> w[i];
    }

    FOR(1, n - 1, 1) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 1);

    FOR(1, n, 1) {
        org[start_time[i]] = w[i];
    }

    // FOR(1,n,1){
    //     UpdateFenwick(i,org[i],n);
    // }
    // FOR(1,n,1){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    buildFenwick(n);

    // FOR(1,n,1){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    
    FOR(1, m, 1) {
        int x;
        cin >> x;
        if (x == 1) {
            int y;
            ll val;
            cin >> y >> val;
            UpdateFenwick(start_time[y], val-org[start_time[y]], n);
            org[start_time[y]] = val;
        } else {
            int y;
            cin >> y;
            int starty = start_time[y];
            int endy = end_time[y];
            
            cout << QueryFenwick(endy) - QueryFenwick(starty - 1) << "\n";
        }
        //  FOR(1,n,1){
        //     cout<<org[i]<<" ";
        // }
        // cout<<endl;
        //  FOR(1,n,1){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
    }

    return 0;
}
