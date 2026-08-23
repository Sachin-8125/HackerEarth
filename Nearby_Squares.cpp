#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> a;

long long solve(int i, long long sb, long long sc) {
    if (i == n) return llabs(sb * sb - sc * sc);
    return min(solve(i + 1, sb + a[i], sc), solve(i + 1, sb, sc + a[i]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(0, 0, 0) << "\n";
    }
    return 0;
}
