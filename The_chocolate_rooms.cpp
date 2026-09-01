#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

void solve() {
    int N;
    long long K;
    if (!(cin >> N >> K)) return;

    unordered_set<string> unique_brands;

    for (int i = 0; i < N; ++i) {
        int P;
        cin >> P;
        for (int j = 0; j < P; ++j) {
            string brand;
            cin >> brand;
            unique_brands.insert(brand);
        }
    }

    if (unique_brands.size() >= K) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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