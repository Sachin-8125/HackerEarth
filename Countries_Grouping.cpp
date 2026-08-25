#include <iostream>
#include <vector>

using namespace std;

int solve(const vector<int>& a, int idx, int n) {
    if (idx == n) {
        return 0;
    }
    
    int x = a[idx];
    
    if (idx + x > n) {
        return -1; 
    }
    
    for (int j = idx; j < idx + x; j++) {
        if (a[j] != x) {
            return -1;
        }
    }
    
    int remainingCountries = solve(a, idx + x, n);
    
    if (remainingCountries == -1) {
        return -1;
    }
    
    return 1 + remainingCountries;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int ans = solve(a, 0, n);
    
    if (ans == -1) {
        cout << "Invalid Data\n";
    } else {
        cout << ans << "\n";
    }
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