#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 10, mod = 1e9 + 7;
int fact[N];

// Fast exponentiation
int binExp(int a, int b, int m) {
    int res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int a = binExp(2, k, mod);
    int num = fact[n];
    int den = fact[n - k] * fact[k] % mod;
    num = num * binExp(den, mod - 2, mod) % mod;
    cout << num * a % mod << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % mod;
    int t; cin >> t;
    while (t--) solve();
}
