#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long solve(long long n) {
    long long sigma = 0;
    
    // Find sum of all divisors of n
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sigma = (sigma + i) % MOD;
            if (i != n / i) {
                sigma = (sigma + n / i) % MOD;
            }
        }
    }
    
    // Return 2 * (sum of proper divisors)
    // Sum of proper divisors = sigma - n
    long long result = (2 * (sigma - n)) % MOD;
    if (result < 0) {
        result += MOD;
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    cin >> n;
    cout << solve(n) << endl;
    
    return 0;
}
