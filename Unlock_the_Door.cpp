#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

long long mod_pow(long long a, long long e) {
    long long r = 1;
    while (e > 0) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
if (!(cin >> T)) return 0;

    vector<long long> N(T), K(T);
    long long maxK = 0;
    for (int i = 0; i < T; ++i) {
        cin >> N[i] >> K[i];
        maxK = max(maxK, K[i]);
    }

    
    vector<long long> fact(maxK + 1), invFact(maxK + 1);
    fact[0] = 1;
    for (long long i = 1; i <= maxK; ++i) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    invFact[maxK] = mod_pow(fact[maxK], MOD - 2);
    for (long long i = maxK; i > 0; --i) {
        invFact[i-1] = (invFact[i] * i) % MOD;
    }

    
    for (int i = 0; i < T; ++i) {
        long long n = N[i], k = K[i];
        
        long long ans = fact[k];
        ans = (ans * invFact[k - n]) % MOD;
        cout << ans << '\n';
    }

    return 0;
}