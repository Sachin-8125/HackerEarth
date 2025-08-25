#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        int maxDist = -1;
        
        // For each character, find first and last occurrence
        for (char c = 'a'; c <= 'z'; c++) {
            int first = -1, last = -1;
            
            // Find first occurrence
            for (int i = 0; i < n; i++) {
                if (s[i] == c) {
                    first = i;
                    break;
                }
            }
            
            // If character found, find last occurrence
            if (first != -1) {
                for (int i = n - 1; i >= 0; i--) {
                    if (s[i] == c) {
                        last = i;
                        break;
                    }
                }
                
                // If there are at least 2 occurrences
                if (last > first) {
                    int dist = last - first - 1;
                    maxDist = max(maxDist, dist);
                }
            }
        }
        
        // If no repeated characters found, print 1
        if (maxDist == -1) {
            cout << 1 << endl;
        } else {
            cout << maxDist << endl;
        }
    }
    
    return 0;
}