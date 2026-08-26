#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> f;
    f.push_back(1);
    f.push_back(1);

    int p = 0;
    for (int i = 2; ; ++i) {
        int nxt = (5 * f[i - 1] + 3 * f[i - 2]) % 1000;
        f.push_back(nxt);
        
        if (f[i] == 1 && f[i - 1] == 1) {
            p = i - 1;
            break;
        }
    }

    int n;
    if (cin >> n) {
        long long k_mod = 1;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            k_mod = (k_mod * (x % p)) % p;
        }
        
        cout << f[k_mod] << "\n";
    }

    return 0;
}