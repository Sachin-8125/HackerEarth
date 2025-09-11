#include <iostream>
#include <vector>
using namespace std;
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n;
    cin >> n;
    const int BITS = 32;
    vector<vector<int>> prefix_sum_bits(n + 1, vector<int>(BITS, 0));
    for (int i = 0; i < n; ++i) {
        int current_val;
        cin >> current_val;
        for (int j = 0; j < BITS; ++j) {
            // Copy previous counts and add 1 if the current bit is set.
            prefix_sum_bits[i + 1][j] = prefix_sum_bits[i][j] + ((current_val >> j) & 1);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long xor_sum_result = 0;
        for (int j = 0; j < BITS; ++j) {
            long long set_bits_in_range1 = prefix_sum_bits[x2][j] - prefix_sum_bits[x1 - 1][j];
            long long len1 = x2 - x1 + 1;
            long long set_bits_in_range2 = prefix_sum_bits[y2][j] - prefix_sum_bits[y1 - 1][j];
            long long len2 = y2 - y1 + 1;
            long long count_pairs_parity = (set_bits_in_range1 * len2 + set_bits_in_range2 * len1) % 2;
            if (count_pairs_parity == 1) {
                xor_sum_result |= (1LL << j);
            }
        }
        cout << xor_sum_result << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}

