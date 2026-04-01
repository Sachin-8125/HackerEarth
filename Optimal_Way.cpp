#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    vector<long long> dp(1 << n, -1);
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); ++mask) {
        if (dp[mask] == -1) continue;

        int r = __builtin_popcount(mask) / 2;
        if (r == k) continue; 

        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) {
                for (int j = i + 1; j < n; ++j) {
                    if (!(mask & (1 << j))) {
                        int next_mask = mask | (1 << i) | (1 << j);
                        long long score = dp[mask] + 1LL * (r + 1) * (a[i] & a[j]);
                        if (score > dp[next_mask]) {
                            dp[next_mask] = score;
                        }
                    }
                }
            }
        }
    }

    long long max_score = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (__builtin_popcount(mask) == 2 * k) {
            max_score = max(max_score, dp[mask]);
        }
    }

    cout << max_score << "\n";

    return 0;
}