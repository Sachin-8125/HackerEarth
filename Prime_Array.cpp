#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Precompute primes up to maxVal using sieve
vector<bool> sieve(int maxVal) {
    vector<bool> isPrime(maxVal + 1, true);
    isPrime[0] = false; isPrime[1] = false;
    for (int i = 2; i * i <= maxVal; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxVal; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}

long long atestcase(int n, const vector<int>& a, const vector<bool>& isPrime) {
    int ones = 0;
    int primeCount = 0;
    for (int x : a) {
        if (x == 1) ones++;
        if (x < (int)isPrime.size() && isPrime[x]) primeCount++;
    }
    if (ones < 2) return 0;
    // Use long long to avoid overflow
    return (long long)primeCount * ones * (ones - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tno;
    cin >> tno;

    // To optimize, find max element across all test cases first
    // But since input is online, we will assume max element <= 10^6 (adjust if needed)
    const int MAX_VAL = 1000000;
    vector<bool> isPrime = sieve(MAX_VAL);

    while (tno--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int maxElem = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] > maxElem) maxElem = a[i];
        }

        // If maxElem > MAX_VAL, you may want to handle separately or increase MAX_VAL

        cout << atestcase(n, a, isPrime) << "\n";
    }
    return 0;
}


