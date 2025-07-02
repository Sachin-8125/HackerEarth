#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

// Function to process the given input array and compute the result
void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    ll s = 0, p = 0, m = 0, cur;

    // Input values and compute initial sums
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] > 0) p += arr[i];   // Sum of positive numbers
        if (arr[i] < 0) m += arr[i];   // Sum of negative numbers

        // Ignore index out-of-bounds
        if (i - k < 0) continue;

        cur = arr[i - k];

        if (cur > 0) {
            m += cur;  // Adjust negative sum
            if (m > 0) {
                s += m;
                m = 0;
            }
            p -= cur;  // Adjust positive sum
        }
    }

    cout << s + abs(p + m) << endl;
}

int main() {
    IOS;
    solve();
    return 0;
}