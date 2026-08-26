#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                int j = i;
                while (j < n && a[j] % 2 == 0) {
                    j++;
                }
                reverse(a.begin() + i, a.begin() + j);
                i = j - 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}