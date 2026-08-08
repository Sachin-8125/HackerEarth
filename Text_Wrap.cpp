#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    if(!(cin >> n >> k)) return 0;
    vector<long long> a(n);
    long long mx = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }
    long long lo = mx, hi = sum + (n - 1);
    auto good = [&](long long w) {
        int lines = 1;
        long long cur = a[0];
        for (int i = 1; i < n; ++i) {
            if (cur + 1 + a[i] <= w) {
                cur += 1 + a[i];
            } else {
                ++lines;
                cur = a[i];
            }
        }
        return lines <= k;
    };
    while (lo < hi) {
        long long mid = (lo + hi) >> 1;
        if (good(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
    return 0;
}