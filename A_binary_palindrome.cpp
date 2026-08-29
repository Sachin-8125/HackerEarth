#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void generatePalindromes(int len, int pos, string s, vector<long long>& pals) {
    if (pos == (len + 1) / 2) {
        string p = s;
        for (int i = len / 2 - 1; i >= 0; i--) {
            p += s[i];
        }
        pals.push_back(stoll(p, nullptr, 2));
        return;
    }
    generatePalindromes(len, pos + 1, s + "0", pals);
    generatePalindromes(len, pos + 1, s + "1", pals);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> pals;
    pals.push_back(0); 
    
    for (int l = 1; l <= 32; l++) {
        generatePalindromes(l, 1, "1", pals);
    }
    
    sort(pals.begin(), pals.end());

    int t;
    if (cin >> t) {
        while (t--) {
            long long n;
            cin >> n;
            
            auto it = lower_bound(pals.begin(), pals.end(), n);
            long long ans = abs(*it - n);
            
            if (it != pals.begin()) {
                ans = min(ans, abs(*(it - 1) - n));
            }
            
            cout << ans << "\n";
        }
    }
    return 0;
}