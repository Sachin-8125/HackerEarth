#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        sort(a.begin(), a.end(), [&](int u, int v) {
            int du = __builtin_popcount(u ^ x);
            int dv = __builtin_popcount(v ^ x);
            if (du != dv) return du < dv;
            return u < v;
        });
        
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}