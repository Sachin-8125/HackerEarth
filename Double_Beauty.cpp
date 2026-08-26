#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.rbegin(), a.rend());
    
    long long max_beauty = 0;
    for (int i = 0; i < k; ++i) {
        max_beauty += a[i] * 2;
    }
    
    cout << max_beauty << "\n";
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