#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = arr[0];
    for (int i = 1; i < n; ++i) {
        result = gcd(result, arr[i]);
    }

    cout << result << "\n";

    return 0;
}