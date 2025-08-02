#include <iostream>
using namespace std;

long long getsubstring(long long n) {
    long long a = n / 2 + 1;
    long long b = n - n / 2 + 1;
    return a * b - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, low = 0, high = 99999, ans = 1'000'000;
        cin >> n;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (getsubstring(mid) >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << '\n';
    }
}
