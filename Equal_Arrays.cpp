#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n), b(m);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        long long sumA = accumulate(a.begin(), a.end(), 0LL);
        long long sumB = accumulate(b.begin(), b.end(), 0LL);

        if (sumA != sumB) {
            cout << -1 << '\n';
            continue;
        }

        long long sa = 0, sb = 0;
        int i = 0, j = 0, blocks = 0;

        while (i < n && j < m) {
            sa += a[i++];
            sb += b[j++];
            while (sa != sb) {
                if (sa < sb) sa += a[i++];   
                else         sb += b[j++];
            }
            ++blocks;   
            sa = 0;
            sb = 0;
        }
        cout << blocks << '\n';
    }
    return 0;
}