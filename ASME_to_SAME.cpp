#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> count_s(26, 0);
    vector<int> count_t(26, 0);
    int q_count = 0;

    for (char c : s) {
        if (c == '?') {
            q_count++;
        } else {
            count_s[c - 'a']++;
        }
    }

    for (char c : t) {
        count_t[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (count_s[i] > count_t[i]) {
            cout << "No\n";
            return;
        } else {
            q_count -= (count_t[i] - count_s[i]);
        }
    }

    if (q_count >= 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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