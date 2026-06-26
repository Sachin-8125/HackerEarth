#include <iostream>
using namespace std;

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;

    unsigned long long M = 1000000007ULL;
    unsigned long long mod = c * M;

    unsigned __int128 fib_prev = 1;
    unsigned __int128 fib_curr = 1;
    unsigned __int128 fac = 1;
    unsigned __int128 P = 0;

    for (int i = 1; i <= b; ++i) {
        if (i >= a) {
            unsigned __int128 term = (fib_curr * fac) % mod;
            P = (P + term) % mod;
        }
        
        unsigned __int128 next_fib = (fib_prev + fib_curr) % mod;
        fib_prev = fib_curr;
        fib_curr = next_fib;
        fac = (fac * (i + 1)) % mod;
    }

    unsigned long long ans = (unsigned long long)(P / c) % M;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}