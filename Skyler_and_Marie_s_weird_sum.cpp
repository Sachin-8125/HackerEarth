#include <iostream>

using namespace std;

const int MOD = 1000000007;

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
    
    int t;
    if (cin >> t) {
        while (t--) {
            long long n;
            cin >> n;
            
            if (n == 1) {
                cout << 45 << "\n";
            } else {
                long long e = (n - 1) / 2 + n - 2;
                long long ans = (495LL * power(10, e)) % MOD;
                cout << ans << "\n";
            }
        }
    }
    return 0;
}