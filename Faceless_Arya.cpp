#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Maximum constraint value given in the problem
const int MAXA = 1000005;
int spf[MAXA];
long long max_dp[MAXA];

// Sieve to precompute Smallest Prime Factors for O(log X) prime factorization
void sieve() {
    for (int i = 1; i < MAXA; i++) spf[i] = i;
    for (int i = 2; i * i < MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    // Initialize max_dp tracking array with -1
    for (int i = 0; i < MAXA; i++) {
        max_dp[i] = -1;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    // dp[i][j] stores max sum to reach row i, column j
    vector<vector<long long>> dp(n, vector<long long>(m, -1));
    
    // Base Case: Starting anywhere on row 0
    for (int j = 0; j < m; j++) {
        dp[0][j] = A[0][j];
    }

    for (int i = 1; i < n; i++) {
        vector<int> modified_primes;

        // 1. Register the maximum dp values from the PREVIOUS row by their prime factors
        for (int j = 0; j < m; j++) {
            if (dp[i - 1][j] != -1) {
                int x = A[i - 1][j];
                while (x > 1) {
                    int p = spf[x];
                    if (max_dp[p] == -1) {
                        modified_primes.push_back(p);
                    }
                    max_dp[p] = max(max_dp[p], dp[i - 1][j]);
                    
                    // Divide out the current prime factor
                    while (x % p == 0) x /= p;
                }
            }
        }

        // 2. Compute dp values for the CURRENT row
        for (int j = 0; j < m; j++) {
            int x = A[i][j];
            long long best_prev = -1;
            while (x > 1) {
                int p = spf[x];
                if (max_dp[p] != -1) {
                    best_prev = max(best_prev, max_dp[p]);
                }
                
                // Divide out the current prime factor
                while (x % p == 0) x /= p;
            }
            
            if (best_prev != -1) {
                dp[i][j] = best_prev + A[i][j];
            }
        }

        // 3. Clean up the tracking array for the next iteration (avoids O(MAXA) resets)
        for (int p : modified_primes) {
            max_dp[p] = -1;
        }
    }

    // Find the max value achievable in the very last row (Winterfell)
    long long ans = 0;
    for (int j = 0; j < m; j++) {
        ans = max(ans, dp[n - 1][j]);
    }

    // If 'ans' remains 0, it indicates that Winterfell is unreachable.
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}