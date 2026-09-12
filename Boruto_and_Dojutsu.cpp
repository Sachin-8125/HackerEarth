#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int par[MAXN];
set<int>* colors[MAXN];

int find(int x) {
    int root = x;
    while (par[root] != root) root = par[root];
    while (par[x] != root) {
        int nxt = par[x];
        par[x] = root;
        x = nxt;
    }
    return root;
}

void unite(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return;
    if (colors[u]->size() < colors[v]->size()) swap(u, v);
    par[v] = u;
    for (int c : *colors[v]) colors[u]->insert(c);
    delete colors[v];
    colors[v] = nullptr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> col(N + 1);
    for (int i = 1; i <= N; i++) cin >> col[i];

    vector<int> eu(M + 1), ev(M + 1);
    for (int i = 1; i <= M; i++) cin >> eu[i] >> ev[i];

    vector<pair<int,int>> queries(Q);
    for (int i = 0; i < Q; i++) cin >> queries[i].first >> queries[i].second;

    // For each removed edge, record the LAST removal query index
    unordered_map<int,int> lastRem;
    for (int i = 0; i < Q; i++) {
        if (queries[i].first == 1)
            lastRem[queries[i].second] = i;
    }

    // Initialize DSU with color sets
    for (int i = 1; i <= N; i++) {
        par[i] = i;
        colors[i] = new set<int>();
        colors[i]->insert(col[i]);
    }

    // Add edges that are NEVER removed
    for (int i = 1; i <= M; i++) {
        if (lastRem.find(i) == lastRem.end())
            unite(eu[i], ev[i]);
    }

    // Process queries in reverse
    vector<int> ans;
    for (int i = Q - 1; i >= 0; i--) {
        if (queries[i].first == 1) {
            int eidx = queries[i].second;
            if (lastRem[eidx] == i)  // only at last removal
                unite(eu[eidx], ev[eidx]);
        } else {
            int root = find(queries[i].second);
            ans.push_back((int)colors[root]->size());
        }
    }

    reverse(ans.begin(), ans.end());
    for (int a : ans) cout << a << "\n";

    return 0;
}