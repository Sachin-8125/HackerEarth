#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Size of array
        
        vector<int> arr(n);
        long long totalSum = 0;
        int minOdd = INT_MAX; // To track smallest odd number
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            totalSum += arr[i];
            if (arr[i] % 2 != 0) {
                minOdd = min(minOdd, arr[i]);
            }
        }
        
        if (totalSum % 2 != 0) {
            cout << totalSum << "\n";
        } else {
            if (minOdd == INT_MAX) {
                cout << 0 << "\n";
            } else {
                cout << totalSum - minOdd << "\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
