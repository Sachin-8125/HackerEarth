#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    long long total_or = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        total_or |= a[i];
    }

    if (total_or == 0) {
        cout << 1 << " " << n << "\n";
        return;
    }

    vector<int> first(32, 0), last(32, 0);
    for (int i = 1; i <= n; i++) {
        for (int bit = 0; bit < 32; bit++) {
            if ((a[i] >> bit) & 1) {
                if (first[bit] == 0) first[bit] = i;
                last[bit] = i;
            }
        }
    }

    vector<int> bits;
    for (int bit = 0; bit < 32; bit++) {
        if ((total_or >> bit) & 1) {
            if (first[bit] == last[bit]) {
                cout << -1 << "\n";
                return;
            }
            bits.push_back(bit);
        }
    }

    vector<int> prev(32, 0);
    int cur_bad_l = 0;
    int min_len = n + 1;
    int count = 0;

    for (int r = 1; r <= n; r++) {
        for (int bit : bits) {
            if ((a[r] >> bit) & 1) {
                prev[bit] = r;
            }
        }

        int good_l = r;
        for (int bit : bits) {
            good_l = min(good_l, prev[bit]);
        }

        for (int bit : bits) {
            if (last[bit] == r) {
                cur_bad_l = max(cur_bad_l, first[bit]);
            }
        }

        if (good_l > cur_bad_l) {
            int len = r - good_l + 1;
            if (len < min_len) {
                min_len = len;
                count = 1;
            } else if (len == min_len) {
                count++;
            }
        }
    }

    if (min_len > n) {
        cout << -1 << "\n";
    } else {
        cout << min_len << " " << count << "\n";
    }
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