#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        if (n == 0) {
            cout << 0 << '\n';
        } else if (n == 1) {
            cout << a[0] << '\n';
        } else if (n == 2) {
            cout << abs(a[0] - a[1]) << '\n';
        } else if (n == 3) {
            cout << (a.back() - a[0]) << '\n';
        } else {
            int r = a[0] + a[1];
            int r1 = a[n-1] + a[n-2];
            int res = r1 - r;
            cout << res << '\n';
        }
    }
    return 0;
}
