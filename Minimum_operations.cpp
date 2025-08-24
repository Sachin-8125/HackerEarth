#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        long long sum = 0;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            sum += A[i];
        }
        if (sum >= 0) {
            cout << -1 << '\n';
        } else {
            cout << -sum << '\n';
        }
    }
}

int main() {
    solve();
    return 0;
}
