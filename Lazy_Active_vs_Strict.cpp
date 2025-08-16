#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to compute gcd
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

// Function to generate all proper divisors of n
vector<int> proper_divisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i != n) divisors.push_back(i);
            if (i != n / i && n / i != n) divisors.push_back(n / i); // Avoid repeats and itself
        }
    }
    return divisors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int X;
        cin >> X;
        vector<int> divisors = proper_divisors(X);

        int D = divisors.size();
        int N = 0;

        for (int d : divisors) {
            int rt = (int)sqrt(d);
            if (rt * rt == d && d % 2 == 0) {
                N++;
            }
        }

        if (N == 0 || D == 0) {
            cout << "0\n";
        } else {
            int g = gcd(N, D);
            cout << N / g << "/" << D / g << "\n";
        }
    }
    return 0;
}
