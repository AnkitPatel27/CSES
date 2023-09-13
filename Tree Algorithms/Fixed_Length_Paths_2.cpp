#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int n, k1,k2;
vector<int> graph[200001];
int subtree[200001];
 
ll ans = 0;
ll cnt[200001]{1}, mx_depth;
bool processed[200001];
 
int get_subtree_sizes(int node, int parent = 0) {
	subtree[node] = 1;
	for (int i : graph[node])
		if (!processed[i] && i != parent)
			subtree[node] += get_subtree_sizes(i, node);
	return subtree[node];
}
 
int get_centroid(int desired, int node, int parent = 0) {
	for (int i : graph[node])
		if (!processed[i] && i != parent && subtree[i] >= desired)
			return get_centroid(desired, i, node);
	return node;
}
 
void get_cnt(int node, int parent,ll sum,ll depth = 1) {
	if (depth > k2) return;
	mx_depth = max(mx_depth, depth);
    ans += sum;
    sum -= cnt[k2-depth];
    sum += (k1-depth-1)>=0?cnt[k1-depth-1]:0;
	for (int i : graph[node])
		if (!processed[i] && i != parent) get_cnt(i, node,sum, depth + 1);
}

void get_cnt1(int node, int parent, ll &sum,ll depth = 1) {
	if (depth > k2) return;
	mx_depth = max(mx_depth, depth);
    
    cnt[depth]++;
    if(k1-1<=depth && depth<=k2-1){
        sum++;
    }

	for (int i : graph[node])
		if (!processed[i] && i != parent) get_cnt1(i, node, sum, depth + 1);
}

void centroid_decomp(int node = 1) {
	int centroid = get_centroid(get_subtree_sizes(node) >> 1, node);
	processed[centroid] = true;
	mx_depth = 0;
    ll sum = 0;
    if(k1-1<=0){
        sum++;
    }
	for (int i : graph[centroid])
		if (!processed[i]) {
            ll temp = sum;
			get_cnt(i, centroid,sum);
			get_cnt1(i, centroid,temp);
            sum = temp;
		}
	fill(cnt + 1, cnt + mx_depth + 1, 0);
	for (int i : graph[centroid])
		if (!processed[i]) centroid_decomp(i);
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k1>>k2;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	centroid_decomp();
	cout << ans;
	return 0;
}