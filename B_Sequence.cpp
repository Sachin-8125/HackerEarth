#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> seq(n);
    for (int i = 0; i < n; i++) scanf("%d", &seq[i]);

    // Find peak index
    int peak_idx = 0;
    for (int i = 1; i < n; i++)
        if (seq[i] > seq[peak_idx]) peak_idx = i;

    int peak = seq[peak_idx];
    set<int> inc, dec;
    for (int i = 0; i < peak_idx; i++) inc.insert(seq[i]);
    for (int i = peak_idx + 1; i < n; i++) dec.insert(seq[i]);

    int q;
    scanf("%d", &q);

    while (q--) {
        int val;
        scanf("%d", &val);

        if (val > peak) {
            inc.insert(peak);
            peak = val;
        } else if (val < peak) {
            if (!inc.count(val))
                inc.insert(val);
            else if (!dec.count(val))
                dec.insert(val);
        }
        // val == peak: do nothing

        printf("%d\n", (int)(inc.size() + 1 + dec.size()));
    }

    // Print final B-sequence
    for (auto x : inc) printf("%d ", x);
    printf("%d", peak);
    for (auto it = dec.rbegin(); it != dec.rend(); it++)
        printf(" %d", *it);
    printf("\n");

    return 0;
}