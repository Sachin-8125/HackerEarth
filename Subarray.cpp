#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& arr) {
    int n = arr.size();
    int ones = 0, zeros = 0;
    
    // Count ones and zeros
    for (int x : arr) {
        if (x == 1) ones++;
        else zeros++;
    }
    if (ones == 0 || zeros == 0) return 0;
    if (ones > zeros + 1) return -1;
    vector<int> pattern1(n, 0);
    vector<int> pattern2(n, 0);
    
    int ones_placed = 0;
    for (int i = 1; i < n && ones_placed < ones; i += 2) {
        pattern1[i] = 1;
        ones_placed++;
    }
    ones_placed = 0;
    for (int i = 0; i < n && ones_placed < ones; i += 2) {
        pattern2[i] = 1;
        ones_placed++;
    }
    
    // Count swaps needed for each pattern
    int swaps1 = 0, swaps2 = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1 && pattern1[i] == 0) swaps1++;
        if (arr[i] == 1 && pattern2[i] == 0) swaps2++;
    }
    
    return min(swaps1, swaps2);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << solve(arr) << endl;
    }
    
    return 0;
}
