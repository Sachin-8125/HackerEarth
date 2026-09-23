#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using u128 = __uint128_t;

ull mulMod(ull a, ull b, ull mod) {
    return (u128)a * b % mod;
}

ull powMod(ull a, ull e, ull mod) {
    ull result = 1;
    while (e > 0) {
        if (e & 1)
            result = mulMod(result, a, mod);
        a = mulMod(a, a, mod);
        e >>= 1;
    }
    return result;
}

bool isPrime(ull n) {
    if (n < 2) return false;

    for (ull p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {
        if (n % p == 0)
            return n == p;
    }

    ull d = n - 1;
    int s = 0;

    while ((d & 1) == 0) {
        d >>= 1;
        ++s;
    }

    for (ull a : {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL}) {
        if (a % n == 0) continue;

        ull x = powMod(a % n, d, n);

        if (x == 1 || x == n - 1)
            continue;

        bool composite = true;

        for (int r = 1; r < s; ++r) {
            x = mulMod(x, x, n);

            if (x == n - 1) {
                composite = false;
                break;
            }
        }

        if (composite)
            return false;
    }

    return true;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ull pollardRho(ull n) {
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;

    while (true) {
        ull c = rng() % (n - 1) + 1;
        ull x = rng() % (n - 2) + 2;
        ull y = x;
        ull d = 1;

        auto f = [&](ull v) {
            return ((u128)mulMod(v, v, n) + c) % n;
        };

        while (d == 1) {
            x = f(x);
            y = f(f(y));

            ull diff = x > y ? x - y : y - x;
            d = gcd(diff, n);
        }

        if (d != n)
            return d;
    }
}

void factorize(ull n, vector<ull>& factors) {
    if (n == 1) return;

    if (isPrime(n)) {
        factors.push_back(n);
        return;
    }

    ull divisor = pollardRho(n);
    factorize(divisor, factors);
    factorize(n / divisor, factors);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull N;
    cin >> N;

    if (N == 1) {
        cout << 0 << '\n';
        return 0;
    }

    if (N == 2 || N == 4) {
        cout << N - 1 << '\n';
        return 0;
    }

    ull oddPart = N;
    int powerOfTwo = 0;

    while ((oddPart & 1) == 0) {
        oddPart >>= 1;
        ++powerOfTwo;
    }

    if (oddPart == 1) {
        cout << 1 << '\n';
        return 0;
    }

    if (powerOfTwo > 1) {
        cout << 1 << '\n';
        return 0;
    }

    vector<ull> factors;
    factorize(oddPart, factors);

    sort(factors.begin(), factors.end());

    bool oneDistinctPrime = true;

    for (int i = 1; i < (int)factors.size(); ++i) {
        if (factors[i] != factors[0]) {
            oneDistinctPrime = false;
            break;
        }
    }

    cout << (oneDistinctPrime ? N - 1 : 1) << '\n';

    return 0;
}