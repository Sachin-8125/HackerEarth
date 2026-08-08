#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    int k;
    cin >> k;

    int n = (int)s.size();
    if (k > n) {
        cout << 0 << "\n";
        return 0;
    }

    int last[26];
    const int NEG = -1e9;
    for (int i = 0; i < 26; ++i) last[i] = NEG;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int ch = s[i] - 'a';
        if (i - last[ch] < k) {
            ++ans;
        } else {
            last[ch] = i;
        }
    }

    cout << ans << "\n";
    return 0;
}