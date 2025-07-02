#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    long long maxSum = LLONG_MIN;
    vector<int> a(n);
    vector<long long> prefixSum(n);

    long long temp = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        temp += a[i];
        prefixSum[i] = temp;
    }

    for (int i = 0; i < n; i++) {
        int k = (int)((-1 + sqrt(1 + 8.0 * (n - i))) / 2);
        int elementsToInclude = (k * (k + 1)) / 2 - 1;
        long long specialSum = 0;
        specialSum=(i==0 ? prefixSum[elementsToInclude]:prefixSum[i + elementsToInclude] - prefixSum[i - 1]);
        if (specialSum > maxSum) maxSum = specialSum;
    }
    cout << maxSum << endl;
    return 0;
}
