#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long current_sum = 0;
    long long min_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        current_sum += a[i];
        min_sum = min(min_sum, current_sum);
    }

    long long p1 = 1 - min_sum;
    vector<long long> p(n + 1);
    vector<bool> seen(n + 2, false);
    
    p[0] = p1;
    bool valid = (p1 >= 1 && p1 <= n + 1);
    
    if (valid) {
        seen[p1] = true;
    }

    for (int i = 0; i < n && valid; ++i) {
        p[i + 1] = p[i] + a[i];
        if (p[i + 1] < 1 || p[i + 1] > n + 1 || seen[p[i + 1]]) {
            valid = false;
        } else {
            seen[p[i + 1]] = true;
        }
    }

    if (valid) {
        for (int i = 0; i <= n; ++i) {
            cout << p[i] << (i == n ? "" : " ");
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}