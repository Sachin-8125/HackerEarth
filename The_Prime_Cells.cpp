#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    if (!(cin >> n)) return 0;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (auto& r : a) for (auto& x : r) cin >> x;

    const int M = 400;
    vector<char> np(M + 1);
    np[0] = np[1] = 1;
    for (int i = 2; i * i <= M; i++) if (!np[i]) for (int j = i * i; j <= M; j += i) np[j] = 1;

    int ans = 0, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        int s = 0;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < n) s += a[x][y];
        }
        ans += !np[s];
    }
    cout << ans;
}