#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string S;
    cin >> S;
    long long total_ways = 0;
    const int MOD = 1e9 + 7;

    for (int x = 0; x < 9; ++x) {
        char cx = '0' + x;
        char cy = '0' + x + 1;
        
        vector<long long> dp(4, 0);
        
        for (char c : S) {
            if (c == cy) {
                dp[3] = (dp[3] + dp[2]) % MOD;
                dp[2] = (dp[2] + dp[1]) % MOD;
            }
            if (c == cx) {
                dp[1] = (dp[1] + dp[0]) % MOD;
                dp[0] = (dp[0] + 1) % MOD;
            }
        }
        total_ways = (total_ways + dp[3]) % MOD;
    }
    
    cout << total_ways << "\n";
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