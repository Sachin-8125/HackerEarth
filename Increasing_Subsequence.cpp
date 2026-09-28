#include <bits/stdc++.h>
using namespace std;

class FenwickMin {
private:
    int n;
    const long long INF = (long long)4e18;
    vector<long long> tree;

public:
    FenwickMin(int n) {
        this->n = n;
        tree.assign(n + 1, INF);
    }

    void update(int index, long long value) {
        while (index <= n) {
            tree[index] = min(tree[index], value);
            index += index & -index;
        }
    }

    long long query(int index) {
        long long answer = INF;

        while (index > 0) {
            answer = min(answer, tree[index]);
            index -= index & -index;
        }

        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);

    for (long long& value : a) {
        cin >> value;
    }

    // Coordinate compression
    vector<long long> values = a;
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    vector<int> rank(n);

    for (int i = 0; i < n; i++) {
        rank[i] = lower_bound(
            values.begin(),
            values.end(),
            a[i]
        ) - values.begin() + 1;
    }

    const long long INF = (long long)4e18;

    // dp[i] for the previous subsequence length
    vector<long long> previous(n, INF);
    vector<long long> current(n, INF);

    // Base case: subsequence of length 1
    FenwickMin base(values.size());

    for (int i = 0; i < n; i++) {
        previous[i] = a[i];
        base.update(rank[i], previous[i]);
    }

    // Build subsequences of lengths 2 through k
    for (int length = 2; length <= k; length++) {
        FenwickMin fenwick(values.size());
        fill(current.begin(), current.end(), INF);

        for (int i = 0; i < n; i++) {
            current[i] = fenwick.query(rank[i] - 1);

            if (previous[i] != INF) {
                fenwick.update(rank[i], previous[i]);
            }
        }

        previous.swap(current);
    }

    long long answer = -1;

    for (int i = 0; i < n; i++) {
        if (previous[i] != INF) {
            long long energy = a[i] - previous[i];
            answer = max(answer, energy);
        }
    }

    cout << answer << '\n';

    return 0;
}