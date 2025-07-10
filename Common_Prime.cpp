#include <bits/stdc++.h>
using namespace std;
long long solve(long long A, long long B) {
    long long k = __gcd(A, B);
    if (k == 1) return -1; 
    for (long long i = 2; i * i <= k; ++i) {
        if (k % i == 0) return i;
    }
    return k;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long A, B;
    cin >> A >> B;
    long long result = solve(A, B);
    cout << result << endl;
    return 0;
}
