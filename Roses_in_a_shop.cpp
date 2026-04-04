#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n <= 1) {
        cout << n << "\n";
        return 0;
    }

    vector<int> left(n, 1);
    int max_len = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
        max_len = max(max_len, left[i]);
    }

    vector<int> right(n, 1);
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] < a[i + 1]) {
            right[i] = right[i + 1] + 1;
        }
    }

    for (int i = 1; i < n - 1; ++i) {
        if (a[i - 1] < a[i + 1]) {
            max_len = max(max_len, left[i - 1] + right[i + 1]);
        }
    }

    cout << max_len << "\n";

    return 0;
}