#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;
    string a, b;
    cin >> a >> b;

    vector<int> pos;
    pos.reserve(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            pos.push_back(i);
        }
    }

    if (pos.size() % 2 != 0) {
        cout << -1 << "\n";
        return;
    }

    if (pos.empty()) {
        cout << 0 << "\n";
        return;
    }

    int m = pos.size();
    vector<long long> dp(m + 1, 0);
    
    dp[0] = 0;
    dp[1] = x;
    
    for (int i = 2; i <= m; ++i) {
        dp[i] = min(dp[i - 1] + x, dp[i - 2] + 2LL * (pos[i - 1] - pos[i - 2]));
    }
    
    cout << dp[m] / 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}