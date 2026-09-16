#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        bool present[26] = {};
        int distinct = 0;

        for (char ch : s) {
            int index = ch - 'a';

            if (!present[index]) {
                present[index] = true;
                distinct++;
            }
        }

        if (distinct % 2 == 1) {
            cout << "Player1\n";
        } else {
            cout << "Player2\n";
        }
    }

    return 0;
}