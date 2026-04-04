#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    if (n <= 0) {
        cout << 0 << "\n";
        return 0;
    }

    const int MOD = 1e9 + 7;
    vector<int> dp(n + 1, 0);
    
    dp[1] = 1;
    long long window_sum = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = window_sum;
        window_sum = (window_sum + dp[i]) % MOD;
        
        if (i >= k + 1) {
            window_sum = (window_sum - dp[i - k] + MOD) % MOD;
        }
    }

    cout << dp[n] << "\n";

    return 0;
}