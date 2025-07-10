#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

vector<int> solve(const vector<int>& A, const vector<int>& R, const vector<int>& L) {
    int n = A.size(), m = L.size();
    vector<int> sum(n+1, 0), ans(m);
    for (int i = 0; i < n; i++) sum[i+1] = (sum[i] + A[i]) % MOD;
    for (int i = 0; i < m; i++) {
        int l = L[i]-1, r = R[i];
        int total = ((sum[n] * ((r/n - l/n) % MOD)) % MOD + sum[r%n] - sum[l%n]) % MOD;
        ans[i] = (total + MOD) % MOD;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N);
        for (int& x : A) cin >> x;
        int Q; cin >> Q;
        vector<int> L(Q), R(Q);
        for (int& x : L) cin >> x;
        for (int& x : R) cin >> x;
        vector<int> res = solve(A, R, L);
        for (int i = 0; i < Q; i++) cout << (i ? " " : "") << res[i];
        cout << "\n";
    }
}
