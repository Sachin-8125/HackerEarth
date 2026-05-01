#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n, long long p) {
    return power(n, p - 2, p);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long p;
    if (!(cin >> n >> p)) return 0;

    vector<int> count(p, 0);
    for (int i = 0; i < n; ++i) {
        long long h;
        cin >> h;
        count[h % p]++;
    }

    long long max_set_size = count[0];
    vector<bool> visited(p, false);

    for (long long i = 2; i < p - 1; ++i) {
        if (!visited[i]) {
            long long inv = modInverse(i, p);
            max_set_size += max(count[i], count[inv]);
            visited[i] = true;
            visited[inv] = true;
        }
    }

    cout << max_set_size << "\n";

    return 0;
}