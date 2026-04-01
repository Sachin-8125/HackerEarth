#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<long long> masks;
    masks.push_back(x);
    
    for (int k = 0; k <= 29; ++k) {
        if (((x >> k) & 1) == 0) {
            long long mask = (x >> (k + 1)) << (k + 1);
            mask |= (1LL << k);
            masks.push_back(mask);
        }
    }
    
    int max_len = -1;
    for (long long mask : masks) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if ((a[i] & mask) == mask) {
                count++;
            }
        }
        if (count > 0 && count > max_len) {
            max_len = count;
        }
    }
    
    cout << max_len << "\n";
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