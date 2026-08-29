#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int idx, const vector<int>& arr, vector<int>& memo) {
    if (idx >= arr.size() - 1) return 0;
    if (arr[idx] == 0) return 1e9;
    if (memo[idx] != -1) return memo[idx];

    int jumps = 1e9;
    for (int i = 1; i <= arr[idx]; i++) {
        jumps = min(jumps, 1 + solve(idx + i, arr, memo));
    }

    return memo[idx] = jumps;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        vector<int> memo(n, -1);
        int ans = solve(0, arr, memo);
        
        cout << (ans >= 1e9 ? -1 : ans) << "\n";
    }
    return 0;
}