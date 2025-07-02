#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isSpecial(int n) {
    int primeCount = 0;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            if (isPrime(i)) {
                primeCount++;
            }
            n /= i;
        }
    }
    if (n > 1 && isPrime(n)) {
        primeCount++;
    }
    return primeCount == 3;
}

int countNonPrimePairs(int n) {
    if (isSpecial(n)) return -1;
    vector<int> nonPrimeFactors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (!isPrime(i)) nonPrimeFactors.push_back(i);
            if (i * i != n && !isPrime(n / i)) nonPrimeFactors.push_back(n / i);
        }
    }
    sort(nonPrimeFactors.begin(), nonPrimeFactors.end());
    int count = 0;
    int i = 0, j = nonPrimeFactors.size() - 1;
    while (i < j) {
        if ((nonPrimeFactors[i]) * nonPrimeFactors[j] == n) {
            count++;
            i++;
            j--;
        } else {
            nonPrimeFactors[i] * nonPrimeFactors[j] < n ? i++ : j--;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << countNonPrimePairs(n) << endl;
    }
    return 0;
}