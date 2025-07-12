#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1), col(n + 1, -1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= m; ++i) {
            int b; cin >> b;
            for (int j = i; j <= n; j += i)
                if (col[j] == -1 && a[j] - b <= 0)
                    col[j] = i;
        }
        for (int i = 1; i <= n; ++i)
            cout << col[i] << '\n';
    }
}
