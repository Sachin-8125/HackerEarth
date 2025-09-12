#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        unsigned long long or_all = 0;
        unsigned long long and_all = ~0ULL;
        for (int i = 0; i < n; ++i) {
            unsigned long long x;
            cin >> x;
            or_all |= x;
            and_all &= x;
        }
        unsigned long long mixed = or_all ^ and_all;
        int m = __builtin_popcountll(mixed);
        unsigned long long ans = (m >= 64) ? 0ULL : (1ULL << m); // m won't reach 64 for typical constraints
        cout << ans << "\n";
    }
    return 0;
}
