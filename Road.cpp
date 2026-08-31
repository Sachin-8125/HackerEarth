#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<int>> dp(51, vector<int>(k + 1, -1));
    dp[a[0]][0] = 1;

    for (int i = 1; i < n; ++i) {
        int current_val = a[i];
        vector<int> next_dp = dp[current_val];

        for (int v = 0; v <= 50; ++v) {
            int cost = abs(v - current_val);
            if (cost > k) continue;

            for (int t = 0; t <= k - cost; ++t) {
                if (dp[v][t] != -1) {
                    if (dp[v][t] + 1 > next_dp[t + cost]) {
                        next_dp[t + cost] = dp[v][t] + 1;
                    }
                }
            }
        }
        dp[current_val] = next_dp;
    }

    int max_points = 0;
    for (int v = 0; v <= 50; ++v) {
        for (int t = 0; t <= k; ++t) {
            if (dp[v][t] > max_points) {
                max_points = dp[v][t];
            }
        }
    }

    cout << max_points << "\n";
    return 0;
}