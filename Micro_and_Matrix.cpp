#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// Main algorithm
int main() {
    fast_io();
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> A(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> A[i][j];

        // dp[i][j] = largest X of sub-square ending at (i,j) with same value
        vector<vector<int>> dp(N, vector<int>(N, 1));
        int result = 1;

        for (int i = 1; i < N; i++) {
            for (int j = 1; j < N; j++) {
                if (A[i][j] == A[i-1][j] && A[i][j] == A[i][j-1] && A[i][j] == A[i-1][j-1]) {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }
        cout << result << "\n";
    }
    return 0;
}