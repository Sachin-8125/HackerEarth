#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;

ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll get_primitive_root(ll P) {
    if (P == 2) return 1;
    vector<ll> fact;
    ll phi = P - 1, n = phi;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) fact.push_back(n);

    for (ll res = 2; res <= P; ++res) {
        bool ok = true;
        for (ll q : fact) {
            if (power(res, phi / q, P) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return res;
    }
    return -1;
}

void solve() {
    ll P, L;
    while (cin >> P >> L) {
        if (P == 2) {
            cout << 0 << "\n";
            continue;
        }

        vector<ll> divisors;
        for (ll i = 1; i * i <= P - 1; ++i) {
            if ((P - 1) % i == 0) {
                divisors.push_back(i);
                if (i * i != P - 1) {
                    divisors.push_back((P - 1) / i);
                }
            }
        }

        ll g = get_primitive_root(P);
        vector<int> is_valid(P + 1, 0);
        vector<char> in_Hd(P, 0);

        for (ll d : divisors) {
            ll u = power(g, d, P);
            ll size = (P - 1) / d;
            
            ll curr = 1;
            vector<ll> elements;
            elements.reserve(size);
            for (int i = 0; i < size; ++i) {
                elements.push_back(curr);
                in_Hd[curr] = 1;
                curr = (curr * u) % P;
            }

            bool found = false;
            for (ll x : elements) {
                if (in_Hd[(x + 1) % P]) {
                    found = true;
                    break;
                }
            }
            
            for (ll x : elements) {
                in_Hd[x] = 0;
            }
            
            is_valid[d] = found;
        }

        ll full_cycles = L / (P - 1);
        ll remaining = L % (P - 1);
        ll valid_in_period = 0;
        ll extra = 0;

        for (ll k = 1; k <= P - 1; ++k) {
            ll d = gcd(k, P - 1);
            if (is_valid[d]) {
                valid_in_period++;
                if (k <= remaining) extra++;
            }
        }

        ll ans = full_cycles * valid_in_period + extra;
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}