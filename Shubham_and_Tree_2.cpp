#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e16;

int n;
vector<int> adj[5005];
int color[5005];
long long joy[5005];
vector<long long> dp[5005];
int sz_b[5005];
long long ans[5005];

void dfs(int u, int p) {
    sz_b[u] = (color[u] == 1);
    dp[u].assign(sz_b[u] + 1, -INF);
    dp[u][color[u]] = joy[u];

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);

        int next_sz_b = sz_b[u] + sz_b[v];
        vector<long long> next_dp(next_sz_b + 1, -INF);

        for (int i = 0; i <= sz_b[u]; ++i) {
            if (dp[u][i] <= -INF) continue;
            
            if (next_dp[i] < dp[u][i]) {
                next_dp[i] = dp[u][i];
            }

            for (int j = 0; j <= sz_b[v]; ++j) {
                if (dp[v][j] <= -INF) continue;
                long long new_joy = dp[u][i] + dp[v][j];
                if (next_dp[i + j] < new_joy) {
                    next_dp[i + j] = new_joy;
                }
            }
        }
        sz_b[u] = next_sz_b;
        dp[u] = move(next_dp);
        vector<long long>().swap(dp[v]);
    }

    for (int i = 0; i <= sz_b[u]; ++i) {
        if (i > 0 && ans[i] < dp[u][i]) {
            ans[i] = dp[u][i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        if (u >= 1 && u <= n && v >= 1 && v <= n) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    for (int i = 1; i <= n; ++i) cin >> color[i];
    for (int i = 1; i <= n; ++i) cin >> joy[i];
    
    for (int i = 1; i <= n; ++i) ans[i] = -INF;

    dfs(1, 0);

    for (int i = 1; i <= n; ++i) {
        if (ans[i] <= -INF / 2) {
            cout << "Not Found\n";
        } else {
            cout << ans[i] << "\n";
        }
    }

    return 0;
}