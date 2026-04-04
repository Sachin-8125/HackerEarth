#include <iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<long long> prefix(n), suffix(n);
        
        // Calculate prefix sums
        prefix[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + a[i];
        }
        
        // Calculate suffix sums
        suffix[n-1] = a[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffix[i] = suffix[i+1] + a[i];
        }
        
        // Find minimum valid difference
        long long min_diff = LONG_LONG_MAX;
        for (int i = 0; i < n-1; i++) {
            long long diff = abs(prefix[i] - suffix[i+1]);
            if (suffix[i+1] >= prefix[i] && diff < min_diff) {
                min_diff = diff;
            }
        }
        
        // Output result
        if (min_diff == LLONG_MAX) {
            cout << "-1\n";
        } else {
            cout << min_diff << "\n";
        }
    }
    
    return 0;
}