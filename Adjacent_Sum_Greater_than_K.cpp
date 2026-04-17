#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    if (K <= 2) {
        for (int i = 1; i <= N; i++) cout << i << (i == N ? "" : " ");
        cout << "\n";
        return;
    }

    vector<int> res;
    set<int> seen;
    for (int i = 1; i <= N; i++) seen.insert(i);

    // Start with the smallest possible number
    int curr = 1;
    res.push_back(curr);
    seen.erase(curr);

    bool possible = true;
    for (int i = 1; i < N; i++) {
        // Find the smallest x such that curr + x >= K
        auto it = seen.lower_bound(K - curr);
        
        if (it == seen.end()) {
            possible = false;
            break;
        }

        curr = *it;
        res.push_back(curr);
        seen.erase(it);
    }

    if (!possible) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < N; i++) {
            cout << res[i] << (i == N - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}