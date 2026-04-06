#include <iostream>
#include <numeric>

using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    long long g = std::gcd(a, b);
    cout << (b / g) << " " << (a / g) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}