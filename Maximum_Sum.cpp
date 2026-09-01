#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    set<long long> unique_max_sums;

    for (int i = 0; i < N; ++i) {
        long long curr_max = 0;
        long long range_max = -2e18;

        for (int j = i; j < N; ++j) {
            if (j == i) {
                curr_max = A[j];
                range_max = A[j];
            } else {
                curr_max = max(A[j], curr_max + A[j]);
                range_max = max(range_max, curr_max);
            }
            unique_max_sums.insert(range_max);
        }
    }

    long long total_sum = 0;
    for (long long val : unique_max_sums) {
        total_sum += val;
    }

    cout << total_sum << endl;

    return 0;
}