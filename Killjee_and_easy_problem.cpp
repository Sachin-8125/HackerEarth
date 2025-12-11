#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using u64 = unsigned long long;

static const int64 MOD = 10000000011LL; // 10^10 + 11

// Fast modular exponentiation
int64 modpow(int64 base, int64 exp, int64 mod) {
    int64 res = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        int bi = __builtin_popcountll(a[i]); // number of set bits in a[i]
        long long term = modpow((long long)bi, (long long)(i + 1), MOD);
        ans += term;
        if (ans >= MOD) ans -= MOD;
    }

    cout << ans % MOD << "\n";
    return 0;
}