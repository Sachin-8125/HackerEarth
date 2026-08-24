#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;

ll modpow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

pair<ll, ll> geomSum(ll c, ll k) {
    if (k == 0) return make_pair(1LL, 0LL);
    pair<ll, ll> h = geomSum(c, k >> 1);
    ll pw = h.first, sm = h.second;
    ll s = sm * ((1 + pw) % MOD) % MOD;
    ll p = pw * pw % MOD;
    if (k & 1) {
        s = (s + p) % MOD;
        p = p * c % MOD;
    }
    return make_pair(p, s);
}

ll solve(ll x, ll y) {
    vector<pair<ll, ll> > ch;
    ll a = x, b = y;
    ch.push_back(make_pair(a, b));
    while (a % b != 0) {
        ll r = a % b;
        a = b; b = r;
        ch.push_back(make_pair(a, b));
    }
    int n = (int)ch.size();

    vector<ll> F(n);
    F[n - 1] = modpow(2, ch[n - 1].first - 1);

    for (int i = n - 2; i >= 0; --i) {
        ll A = ch[i].first, B = ch[i].second;
        ll r = A % B, q = A / B;
        ll block = F[i + 1];
        ll tail;
        if (i + 2 < n) tail = F[i + 2];
        else           tail = modpow(2, r - 1);
        ll c = modpow(2, B);
        ll R = geomSum(c, q).second;
        F[i] = ((block * R % MOD) * modpow(2, r) + tail) % MOD;
    }
    return F[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    unordered_map<ll, ll> memo;
    while (T--) {
        ll x, y;
        cin >> x >> y;
        ll key = (x << 30) | y;
        auto it = memo.find(key);
        if (it != memo.end()) cout << it->second << '\n';
        else {
            ll ans = solve(x, y);
            memo[key] = ans;
            cout << ans << '\n';
        }
    }
    return 0;
}