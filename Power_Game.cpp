#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<pair<int,int>> adj[MAXN];
int pw[MAXN];
int disc[MAXN], low[MAXN];
bool visited[MAXN];
int timer_val = 0;
vector<int> bridge_weights;

void dfs(int u, int par_edge) {
    visited[u] = true;
    disc[u] = low[u] = timer_val++;
    for (auto& [v, idx] : adj[u]) {
        if (idx == par_edge) continue;
        if (visited[v]) {
            low[u] = min(low[u], disc[v]);
        } else {
            dfs(v, idx);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                bridge_weights.push_back(pw[idx]);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d", &pw[i]);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    dfs(1, -1);

    // Sort bridges in decreasing order of weight
    sort(bridge_weights.rbegin(), bridge_weights.rend());

    // Alternate picks: position 0,2,4... -> first player; 1,3,5... -> second player
    long long first_player = 0, second_player = 0;
    for (int i = 0; i < (int)bridge_weights.size(); i++) {
        if (i % 2 == 0) first_player += bridge_weights[i];
        else second_player += bridge_weights[i];
    }

    // Sam first gets first_player score, Sam second gets second_player score
    long long max_score = max(first_player, second_player);
    long long min_score = min(first_player, second_player);

    printf("%lld %lld\n", max_score, min_score);
    return 0;
}