#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAX = 100000; // adjust if needed
const ll MOD = 1e18; // large enough to avoid overflow since no mod is specified

ll nCr(ll n, ll r) {
    if (r > n || r < 0) return 0;
    if (r > n - r) r = n - r; // symmetry
    ll res = 1;
    for (ll i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;
        // This division is safe because of combinatorial properties
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<ll> A(N), B(N);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    ll sumA_fixed = 0, sumB_fixed = 0;
    int countA = 0, countB = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] == -1) countA++;
        else sumA_fixed += A[i];
        if (B[i] == -1) countB++;
        else sumB_fixed += B[i];
    }

    ll D = sumB_fixed - sumA_fixed;

    // Case 1: Both arrays have -1
    if (countA > 0 && countB > 0) {
        cout << "Infinite\n";
        return 0;
    }

    // Case 2: No variables in either array
    if (countA == 0 && countB == 0) {
        cout << (D == 0 ? 1 : 0) << "\n";
        return 0;
    }

    // Case 3: Variables only in B
    if (countA == 0 && countB > 0) {
        // sum(y_k) = -D >= 0
        if (-D < 0) {
            cout << 0 << "\n";
            return 0;
        }
        ll M = -D;
        // number of solutions = C(M + countB - 1, countB - 1)
        cout << nCr(M + countB - 1, countB - 1) << "\n";
        return 0;
    }

    // Case 4: Variables only in A
    if (countB == 0 && countA > 0) {
        // sum(x_j) = D >= 0
        if (D < 0) {
            cout << 0 << "\n";
            return 0;
        }
        ll M = D;
        // number of solutions = C(M + countA - 1, countA - 1)
        cout << nCr(M + countA - 1, countA - 1) << "\n";
        return 0;
    }

    return 0;
}
