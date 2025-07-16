#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long T, D, x;
    cin >> T >> D >> x;
    if (x == T) {
        cout << "YES\n";
        return 0;
    }
    if (x < T + D) {
        cout << "NO\n";
        return 0;
    }
    long long delta = x - T;
    if ((delta % D == 0) || (delta % D == 1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
