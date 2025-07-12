#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli testCases, arraySize, i;
    cin >> testCases;
    while (testCases--) {
        cin >> arraySize;
        lli arr[arraySize];
        for (i = 0; i < arraySize; i++) {
            cin >> arr[i];
        }
        if (arraySize == 1) {
            cout << arr[0] << "\n";
        } else {
            lli lcm = (arr[0] * arr[1]) / (__gcd(arr[0], arr[1]));
            for (i = 2; i < arraySize; i++) {
                lcm = (lcm * arr[i]) / (__gcd(lcm, arr[i]));
            }
            cout << lcm << "\n";
        }
    }
    return 0;
}