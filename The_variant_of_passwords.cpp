#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string st;
        cin >> st;
        vector<char> res(n);
        int x = 0, y = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            res[i] = st[i];
            if (st[i] == '0') x++;
            else if (st[i] == '1') y++;
        }
        if (x < a) {
            for (int i = 0; i < n && x < a; i++) {
                if (res[i] == '1' && y > b) {
                    res[i] = '0';
                    x++;
                    y--;
                    ans++;
                }
            }
            for (int i = 0; i < n && x < a; i++) {
                if (res[i] == '2') {
                    res[i] = '0';
                    x++;
                    ans++;
                }
            }
        }
        if (y < b) {
            int c = 0;
            for (int i = 0; i < n && y < b; i++) {
                if (res[i] == '0') {
                    c++;
                    if (c > a && x > a) {
                        res[i] = '1';
                        x--;
                        c--;
                        y++;
                        ans++;
                    }
                }
            }
            for (int i = 0; i < n && y < b; i++) {
                if (res[i] == '2') {
                    res[i] = '1';
                    y++;
                    ans++;
                }
            }
        }
        for (int i = n - 1; i >= 0 && x > a; i--) {
            if (res[i] == '0') {
                res[i] = '2';
                x--;
                ans++;
            }
        }
        for (int i = n - 1; i >= 0 && y > b; i--) {
            if (res[i] == '1') {
                res[i] = '2';
                y--;
                ans++;
            }
        }
        cout << ans << '\n';
        sort(res.begin(),res.end());
        for (char c : res) {
            if (c == '0' || c == '1' || c == '2')
                cout << c;
            else
                cout << '2';
            }
        cout << '\n';
    }
}