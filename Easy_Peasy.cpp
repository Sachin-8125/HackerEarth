#include <iostream>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            long long a, b;
            cin >> a >> b;
            long long g = std::gcd(a, b);
            cout << (b / g) << " " << (a / g) << "\n";
        }
    }
    
    return 0;
}