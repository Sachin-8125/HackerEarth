#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

struct Candidate {
    int64 pref;
    int64 value;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        const int64 INF = (1LL << 62);
        Candidate first{INF, 0}, second{INF, 0};
        int64 pref = 0;
        int64 answer = LLONG_MIN;

        auto add_position = [&](int64 value, int64 prefix_before) {
            if (first.pref != INF && first.value == value) {
                first.pref = min(first.pref, prefix_before);
                return;
            }
            if (second.pref != INF && second.value == value) {
                second.pref = min(second.pref, prefix_before);
                if (second.pref < first.pref) swap(first, second);
                return;
            }
            if (prefix_before < first.pref) {
                second = first;
                first = {prefix_before, value};
            } else if (prefix_before < second.pref) {
                second = {prefix_before, value};
            }
        };

        for (int i = 0; i < n; ++i) {
            int64 x;
            cin >> x;

            // Positions already added are exactly possible left endpoints l < i.
            int64 min_prefix = INF;
            if (first.pref != INF && first.value != x) min_prefix = first.pref;
            else if (second.pref != INF) min_prefix = second.pref;

            int64 prefix_after = pref + x;
            if (min_prefix != INF)
                answer = max(answer, prefix_after - min_prefix);

            // Make i available as a left endpoint for subsequent right endpoints.
            add_position(x, pref);
            pref = prefix_after;
        }

        if (answer == LLONG_MIN) cout << "Not Possible\n";
        else cout << answer << '\n';
    }
    return 0;
}
