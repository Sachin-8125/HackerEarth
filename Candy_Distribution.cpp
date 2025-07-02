#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 200005;

vector<int64_t> fact(MAX), invFact(MAX);

// Fast power function
int64_t power(int64_t base, int64_t exp) {
    int64_t res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 1; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}

// Compute nCr % MOD
int64_t nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int T;
    cin >> T;

    while (T--) {
        int N, X, Y;
        cin >> N >> X >> Y;

        if (X + Y != N || X <= Y) {
            cout << 0 << "\n";
            continue;
        }

        int64_t ways = nCr(X + Y, X);
        int64_t fraction = (X - Y) * power(X + Y, MOD - 2) % MOD;
        int64_t validWays = ways * fraction % MOD;

        cout << validWays << "\n";
    }

    return 0;
}



