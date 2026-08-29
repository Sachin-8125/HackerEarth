#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXP = 1000005;

int prime_count[MAXP];
bool is_prime[MAXP];
vector<int> primes;

void precompute_primes() {
    fill(is_prime, is_prime + MAXP, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAXP; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAXP; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int i = 1; i < MAXP; i++) {
        prime_count[i] = prime_count[i - 1];
        if (is_prime[i]) {
            prime_count[i]++;
            primes.push_back(i);
        }
    }
}

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_primes();

    int P, Q;
    if (!(cin >> P >> Q)) return 0;

    int max_M = sqrt(P);
    vector<int> omega(max_M + 1, 0);
    vector<long long> f(max_M + 1, 1);
    vector<long long> fact(30, 1);

    for (int i = 1; i < 30; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    for (int i = 2; i <= max_M; i++) {
        int temp = i;
        long long denominator = 1;
        int total_factors = 0;
        
        for (int p : primes) {
            if (p * p > temp) break;
            if (temp % p == 0) {
                int count = 0;
                while (temp % p == 0) {
                    count++;
                    temp /= p;
                }
                total_factors += count;
                denominator = (denominator * fact[count]) % MOD;
            }
        }
        if (temp > 1) {
            total_factors++;
            denominator = (denominator * fact[1]) % MOD;
        }
        omega[i] = total_factors;
        
        long long inv_denom = power(denominator, MOD - 2);
        f[i] = (fact[total_factors] * inv_denom) % MOD;
    }

    vector<long long> ans(40, 0);

    for (int M = 1; M <= max_M; M++) {
        if (M > 1) {
            int len_even = 2 * omega[M];
            if (len_even < 40) {
                ans[len_even] = (ans[len_even] + f[M]) % MOD;
            }
        }
        
        int len_odd = 2 * omega[M] + 1;
        if (len_odd < 40) {
            long long max_p = P / ((long long)M * M);
            long long cnt = prime_count[max_p];
            ans[len_odd] = (ans[len_odd] + f[M] * cnt) % MOD;
        }
    }

    for (int i = 1; i < 40; i++) {
        ans[i] = (ans[i] + ans[i - 1]) % MOD;
    }

    for (int i = 0; i < Q; i++) {
        long long N;
        cin >> N;
        if (N >= 40) {
            cout << ans[39] << (i == Q - 1 ? "" : " ");
        } else {
            cout << ans[N] << (i == Q - 1 ? "" : " ");
        }
    }
    cout << "\n";

    return 0;
}