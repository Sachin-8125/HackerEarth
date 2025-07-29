#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'
const int mod = 1000000007;
const int MAX = 200007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> v(n, vector<ll>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }

    vector<ll> v1, v2;
    int row = 0, col = 0;
    int limit = max(n, m);

    for (int i = 0; i < limit; ++i) {
        if (row < n) {
            ll rowMin = LLONG_MAX;
            for (int j = 0; j < m; ++j) {
                rowMin = min(rowMin, v[row][j]);
            }
            v1.push_back(rowMin);
            row++;
        }

        if (col < m) {
            ll colMin = LLONG_MAX;
            for (int j = 0; j < n; ++j) {
                colMin = min(colMin, v[j][col]);
            }
            v2.push_back(colMin);
            col++;
        }
    }

    sort(v1.begin(), v1.end(), greater<ll>());
    sort(v2.begin(), v2.end(), greater<ll>());

    cout << min(v1[0], v2[0]) << endl;

    return 0;
}
