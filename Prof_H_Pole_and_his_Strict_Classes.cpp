#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


constexpr int mod = 1000000007;
constexpr int MAX = 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute factorials modulo mod
    vector<long long> fact(MAX + 1, 1);
    for (int i = 1; i <= MAX; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    int t;
    cin >> t;
    vector<string> out_lines;
    for (int test = 0; test < t; ++test) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        long long res = fact[a];
        res = (res * fact[b]) % mod;
        res = (res * fact[c]) % mod;
        out_lines.push_back(to_string(res));
    }
    for (size_t i = 0; i < out_lines.size(); ++i) {
        cout << out_lines[i] << (i + 1 == out_lines.size() ? "" : "\n");
    }
}