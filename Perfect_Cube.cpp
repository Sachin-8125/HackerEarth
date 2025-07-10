#include <bits/stdc++.h>
using namespace std;
const int MAX_A = 101;
vector<int> primes;
unordered_map<int, vector<int>> factorMap;

void sieve(int n) {
    vector<bool> isP(n+1, 1);
    isP[0] = isP[1] = 0;
    for (int i = 2; i * i <= n; i++) if (isP[i])
        for (int j = i*i; j <= n; j += i) isP[j] = 0;
    for (int i = 2; i <= n; i++) if (isP[i]) primes.push_back(i);
}

void buildFactors() {
    factorMap[1] = vector<int>(primes.size());
    for (int i = 2; i <= MAX_A; i++) {
        vector<int> v(primes.size());
        int x = i;
        for (size_t j = 0; j < primes.size(); j++) {
            while (x % primes[j] == 0) v[j]++, x /= primes[j];
            v[j] %= 3;
            if (x == 1) break;
        }
        factorMap[i] = v;
    }
}

string v2s(const vector<int>& v) {
    string s;
    for (int x : v) s += to_string(x) + ",";
    return s;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> A(n); for (int &x : A) cin >> x;
    sieve(MAX_A); buildFactors();
    unordered_map<string, int> cnt;
    vector<int> pf(primes.size());
    cnt[v2s(pf)] = 1;
    long long ans = 0;
    for (int a : A) {
        auto &f = factorMap[a];
        for (size_t i = 0; i < pf.size(); i++) pf[i] = (pf[i] + f[i]) % 3;
        string k = v2s(pf);
        ans += cnt[k]++;
    }
    cout << ans << '\n';
}
