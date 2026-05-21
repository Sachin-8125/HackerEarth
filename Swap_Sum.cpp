#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<long long> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }

    vector<long long> positive_gains;
    positive_gains.reserve(n);

    for (int i = 0; i < n; ++i) {
        long long b_val;
        cin >> b_val;
        if (b_val > a[i]) {
            positive_gains.push_back(b_val - a[i]);
        }
    }

    sort(positive_gains.rbegin(), positive_gains.rend());

    int swaps = min((int)positive_gains.size(), k);
    for (int i = 0; i < swaps; ++i) {
        total_sum += positive_gains[i];
    }

    cout << total_sum << "\n";
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