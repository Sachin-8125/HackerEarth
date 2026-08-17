#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
vector<int> adj[MAXN];
ll subtree_size[MAXN];
int total_cities;

void dfs(int u, int p) {
    subtree_size[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            subtree_size[u] += subtree_size[v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, dummy;

    if (!(cin >> N >> dummy)) return 0;

    total_cities = N + 1;

    for (int i = 0; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    dfs(1, -1);

    vector<ll> multipliers;
    for (int i = 2; i <= total_cities; ++i) {
        ll s = subtree_size[i];
        multipliers.push_back(s * (total_cities - s));
    }

    sort(multipliers.rbegin(), multipliers.rend());
    sort(A.rbegin(), A.rend());

    ll max_total_toll = 0;
    for (int i = 0; i < N; ++i) {
        max_total_toll += multipliers[i] * A[i];
    }

    cout << max_total_toll << endl;

    return 0;
}