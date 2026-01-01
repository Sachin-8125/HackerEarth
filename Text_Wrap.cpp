#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, L;
    cin >> n >> L;
    vector<int> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    
    // Binary search on the minimum width W
    int left = *max_element(words.begin(), words.end());
    int right = 0;
    for (int len : words) right += len;
    right += n - 1; // maximum possible spaces
    
    int ans = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if we can fit all words in <= L lines with width mid
        int lines = 1;
        int current_line = 0;
        bool can_fit = true;
        
        for (int i = 0; i < n; i++) {
            // Try to add word[i] to current line
            if (current_line == 0) {
                // First word in line
                current_line = words[i];
            } else {
                // Check if word fits with 1 space gap
                if (current_line + 1 + words[i] <= mid) {
                    current_line += 1 + words[i];
                } else {
                    // Start new line
                    lines++;
                    current_line = words[i];
                    
                    // Check if single word fits in new line
                    if (words[i] > mid) {
                        can_fit = false;
                        break;
                    }
                }
            }
        }
        
        if (can_fit && lines <= L) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
