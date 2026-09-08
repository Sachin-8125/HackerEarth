#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (k > n) k = n; 

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + arr[i];
    }

    vector<long long> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] + arr[i];
    }

    long long max_sum = 0;

    for (int i = 1; i <= k; ++i) {
        int elements_from_bottom = k - i;
        
        long long current_sum = pref[i] + suff[n - elements_from_bottom];
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << "\n";

    return 0;
}