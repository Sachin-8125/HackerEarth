#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        pos[val] = i;
    }

    int L = pos[0];
    int R = pos[0];

    for (int i = 1; i <= n; i++) {
        if (i == n) {
            cout << 1;
            break;
        }

        long long ans = 0;
        if (pos[i] < L) {
            ans = 1LL * (L - pos[i]) * (n - R);
            L = pos[i];
        } else if (pos[i] > R) {
            ans = 1LL * (L + 1) * (pos[i] - R);
            R = pos[i];
        } else {
            ans = 0;
        }
        
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}