#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_A = 1000000;
const int MAX_FACT = 2500000; 

int spf[MAX_A + 1];
long long fact[MAX_FACT];
long long invFact[MAX_FACT];
int primeCount[MAX_A + 1];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    for (int i = 2; i <= MAX_A; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= MAX_A; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAX_A; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX_FACT; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    invFact[MAX_FACT - 1] = modInverse(fact[MAX_FACT - 1]);
    for (int i = MAX_FACT - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int n, k;
    if (!(cin >> n >> k)) return 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        while (a > 1) {
            primeCount[spf[a]]++;
            a /= spf[a];
        }
    }

    long long ans = 1;
    for (int i = 2; i <= MAX_A; i++) {
        if (primeCount[i] > 0) {
            int e = primeCount[i];
            ans = (ans * nCr(e + k - 1, k - 1)) % MOD;
        }
    }

    cout << ans << "\n";

    return 0;
}