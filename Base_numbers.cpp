#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, n, b;
    while (cin >> a >> n >> b) {
        if (a == 0 || b <= 1 || n <= 0) {
            cout << "0\n";
            continue;
        }

        double L = n - 1;
        double lower = pow(b, L / a);
        double upper = pow(b, (L + 1) / a);

        long long x_min = llceil(lower);  // smallest valid x
        long long x_max = llfloor(upper - 1e-9); // largest valid x (adjusted for precision)

        long long result = max(0LL, x_max - x_min + 1);
        cout << result << '\n';
    }
}

// Optional: ceil and floor for doubles to long longs
long long llceil(double x) {
    return (long long)(ceil(x - 1e-9));
}

long long llfloor(double x) {
    return (long long)(floor(x + 1e-9));
}

