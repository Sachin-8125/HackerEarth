#include <iostream>
using namespace std;

#define MOD 1000000007

int main() {
    int n;
    cin >> n;
    long long ans = 1;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        ans = ans * (x + 1) % MOD;
    }
    ans = (ans - 1 + MOD) % MOD; // To handle negative values safely
    cout << ans << '\n';
    return 0;
}
