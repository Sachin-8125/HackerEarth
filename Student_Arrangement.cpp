#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> pref(N);
    for (int &x : pref) cin >> x;

    vector<int> seats(M, 0);
    set<int> available_rows;
    for (int i = 0; i < M; i++) available_rows.insert(i);

    int count_not_preferred = 0;

    for (int i = 0; i < N; i++) {
        int p = pref[i] - 1;

        // Find row >= p with free seat
        auto it = available_rows.lower_bound(p);
        if (it == available_rows.end()) {
            // wrap around to smallest available row
            it = available_rows.begin();
        }

        if (available_rows.empty()) {
            // no seat available
            count_not_preferred++;
            continue;
        }

        int row = *it;
        seats[row]++;
        if (row != p) count_not_preferred++;

        if (seats[row] == K) {
            // row full, remove from available rows
            available_rows.erase(row);
        }
    }

    cout << count_not_preferred << "\n";
    return 0;
}
