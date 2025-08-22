#include <bits/stdc++.h>
using namespace std;

using int64 = long long;  // safer alias instead of #define

// Function to process each test case
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Prefix sums for zeros and ones
    vector<int> zero(n, 0), one(n, 0);

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) zero[i] = 1;
        if (a[i] == 1) one[i] = 1;

        if (i > 0) {
            zero[i] += zero[i - 1];
            one[i] += one[i - 1];
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        l--;  // convert to 0-based index
        r--;

        // Count zeros in [l, r]
        int x = zero[r] - (l > 0 ? zero[l - 1] : 0);
        // Count ones in [l, r]
        int y = one[r] - (l > 0 ? one[l - 1] : 0);

        // Total possible pairs
        int64 len = r - l + 1;
        int64 totalPairs = (len * (len - 1)) / 2;

        // Subtract invalid pairs (only zeros together + zero-one pairs)
        int64 invalidPairs = (x * (x - 1)) / 2 + (x * y);

        cout << totalPairs - invalidPairs << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
