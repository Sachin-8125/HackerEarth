#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> even, odd;

    for (int x : a) {
        int bits = __builtin_popcount(x);

        if (bits % 2 == 0)
            even.push_back(x);
        else
            odd.push_back(x);
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    for (int x : even)
        cout << x << " ";

    for (int x : odd)
        cout << x << " ";

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}