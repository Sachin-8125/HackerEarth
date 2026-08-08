#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<long long> guards(N + 1);
        for (int i = 1; i <= N; ++i) cin >> guards[i];

        int LOG = 1;
        while ((1 << LOG) <= N) ++LOG;

        vector<vector<int>> up(LOG, vector<int>(N + 1, 0));
        vector<long long> pref(N + 1, 0);
        vector<int> parent(N + 1, 0);

        queue<int> q;
        q.push(1);
        parent[1] = 0;
        pref[1] = guards[1];

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            up[0][v] = parent[v];
            for (int to : adj[v]) {
                if (to == parent[v]) continue;
                parent[to] = v;
                pref[to] = pref[v] + guards[to];
                q.push(to);
            }
        }

        for (int j = 1; j < LOG; ++j) {
            for (int v = 1; v <= N; ++v) {
                up[j][v] = up[j - 1][up[j - 1][v]];
            }
        }

        int Q;
        cin >> Q;
        while (Q--) {
            int city;
            long long rebels;
            cin >> city >> rebels;

            long long threshold = pref[city] - rebels;
            int cur = city;

            for (int j = LOG - 1; j >= 0; --j) {
                int anc = up[j][cur];
                if (anc != 0 && pref[anc] > threshold) {
                    cur = anc;
                }
            }

            cout << cur << '\n';
        }
    }

    return 0;
}