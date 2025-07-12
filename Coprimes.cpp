#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n, last = 0;
    cin >> n;
    for (int i = 1; i < n - 1; ++i)
        if (gcd(i, n) == 1) last = i;
    cout << last << '\n';
}
