#include <bits/stdc++.h>
using namespace std;

long long solve(int N, vector<int>& A) {
    long long sum_A=0;
    for (int i = 0; i < N; i++) {
        sum_A += A[i];
    }
    if (sum_A > 0) return -1;
    long long k = -sum_A;
    bool all_zero = true;
    for (int i = 0; i < N; i++) {
        if (A[i] != 0) {
            all_zero = false;
            break;
        }
    }
    if (all_zero) return 0;
    if (k == 0) return -1;
    long long min_x_sum = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] >= 0) {
            continue;
        } else {
            long long min_x_i = (-A[i] + 1) / 2;
            min_x_sum += min_x_i;
        }
    }
    if (min_x_sum > k) {
        return -1;
    }
    return k;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cout << solve(N, A) << endl;
    }
    return 0;
}
