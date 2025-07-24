#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100005;
vector<int> adj[N];

int dfs(int u, int p) {
    int depth = 0;
    for (int v : adj[u]) {
        if (v != p) {
            depth = max(depth, dfs(v, u));
        }
    }
    return depth + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int bestCenter = -1;
    int maxSize = 1; // start with min

    for (int u = 1; u <= n; ++u) {
        if (adj[u].size() < 5) continue;

        vector<int> depths;
        for (int v : adj[u]) {
            int d = dfs(v, u);
            depths.push_back(d);
        }

        sort(depths.rbegin(), depths.rend());

        if (depths.size() >= 5 && depths[0] >= 3) {
            // 1 base with depth >= 3, add total nodes (base path + other leaves + center)
            int total = 1; // center
            total += depths[0]; // base full path
            total += 4; // four sails: one edge each

            if (total > maxSize || (total == maxSize && u < bestCenter)) {
                maxSize = total;
                bestCenter = u;
            }
        }
    }

    if (maxSize == 1) {
        cout << 1 << '\n';
    } else {
        cout << maxSize << ' ' << bestCenter << '\n';
    }

    return 0;
}