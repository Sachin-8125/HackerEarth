#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        while (q--) {
            int l, r;
            cin >> l >> r;
            unordered_map<int, int> freq;
            int maxFreq = 0;

            // Adjusting l and r for 0-based index
            for (int i = l - 1; i <= r - 1; ++i) {
                freq[a[i]]++;
                maxFreq = max(maxFreq, freq[a[i]]);
            }
            cout << maxFreq << "\n";
        }
    }
}
