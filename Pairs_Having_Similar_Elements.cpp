#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin >> n;
    vector<long long> A(n);
    for (auto &x : A) cin >> x;
    sort(A.begin(), A.end());

    long long sum = 0, count1 = 0, count2 = 0;
    for (long long i = 0; i + 1 < n; ++i) {
        if (A[i + 1] - A[i] == 1) count1++;
        else if (A[i + 1] == A[i]) count2++, count1++;
        else {
            if (count1 != count2)
                sum += (count1 * (count1 + 1)) / 2;
            count1 = count2 = 0;
        }
    }
    // Possible last segment check
    if (count1 != count2)
        sum += (count1 * (count1 + 1)) / 2;

    cout << sum << '\n';
}