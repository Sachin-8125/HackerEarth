#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_VAL = 100005;

struct Query {
    int id;
    int L;
    int R;
    int target_val;
};

long long bit[MAX_VAL];

void update(int idx, int val, int limit) {
    for (; idx <= limit; idx += idx & -idx) {
        bit[idx] += val;
    }
}

long long query(int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

void solve() {
    int N, Q;
    if (!(cin >> N >> Q)) return;

    vector<int> A(N);
    int max_val = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        max_val = max(max_val, A[i]);
    }

    vector<vector<Query>> queries_by_L(N);
    for (int q = 0; q < Q; ++q) {
        int L, R;
        cin >> L >> R;
        queries_by_L[L].push_back({q, L, R, A[R]});
    }

    for (int i = 0; i <= max_val; ++i) {
        bit[i] = 0;
    }

    vector<long long> ans(Q);

    for (int i = 0; i < N; ++i) {
        update(A[i], A[i], max_val);

        for (const auto& q : queries_by_L[i]) {
            long long total_sum = query(max_val);
            long long sum_less_equal = query(q.target_val);
            ans[q.id] = total_sum - sum_less_equal;
        }
    }

    for (int i = 0; i < Q; ++i) {
        cout << ans[i] << (i == Q - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}