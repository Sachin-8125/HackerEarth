#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    long long weight;
};

const int MAXN = 100005;
vector<Edge> adj[MAXN];
long long node_values[MAXN];
long long dist_from_root[MAXN];
long long target_values[MAXN];
int results[MAXN];
set<long long>* subtree_sets[MAXN];

void dfs_calc_targets(int u, int p, long long current_dist) {
    dist_from_root[u] = current_dist;
    target_values[u] = node_values[u] + current_dist;
    for (auto& edge : adj[u]) {
        if (edge.to != p) {
            dfs_calc_targets(edge.to, u, current_dist + edge.weight);
        }
    }
}

void dfs_solve(int u, int p) {
    int largest_child = -1;
    int max_size = -1;

    for (auto& edge : adj[u]) {
        if (edge.to != p) {
            dfs_solve(edge.to, u);
            if ((int)subtree_sets[edge.to]->size() > max_size) {
                max_size = subtree_sets[edge.to]->size();
                largest_child = edge.to;
            }
        }
    }

    if (largest_child == -1) {
        subtree_sets[u] = new set<long long>();
    } else {
        subtree_sets[u] = subtree_sets[largest_child];
    }

    subtree_sets[u]->insert(target_values[u]);

    for (auto& edge : adj[u]) {
        if (edge.to != p && edge.to != largest_child) {
            for (long long val : *subtree_sets[edge.to]) {
                subtree_sets[u]->insert(val);
            }
            delete subtree_sets[edge.to];
        }
    }

    results[u] = subtree_sets[u]->size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= n; ++i) {
        cin >> node_values[i];
    }

    dfs_calc_targets(1, 0, 0);
    dfs_solve(1, 0);

    for (int i = 1; i <= n; ++i) {
        cout << results[i] << "\n";
    }

    return 0;
}