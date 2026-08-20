#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, P;
    int k1, k2;
    cin >> S >> P >> k1 >> k2;

    int n = S.size(), m = P.size();
    int lim = min(n, m);
    k1 = min(k1, lim);
    k2 = min(k2, lim);

    if (k1 + k2 >= lim) {
        cout << lim << endl;
        return 0;
    }

    vector<vector<vector<int>>> cur(m+1, vector<vector<int>>(k1+1, vector<int>(k2+1, 0)));
    vector<vector<vector<int>>> prv(m+1, vector<vector<int>>(k1+1, vector<int>(k2+1, 0)));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int a = 0; a <= k1; a++) {
                for (int b = 0; b <= k2; b++) {
                    cur[j][a][b] = max(prv[j][a][b], cur[j-1][a][b]);

                    if (S[i-1] == P[j-1]) {
                        cur[j][a][b] = max(cur[j][a][b], prv[j-1][a][b] + 1);
                    } else {                     
                        if (a > 0)
                            cur[j][a][b] = max(cur[j][a][b], prv[j-1][a-1][b] + 1);
                        if (b > 0)
                            cur[j][a][b] = max(cur[j][a][b], prv[j-1][a][b-1] + 1);
                    }
                }
            }
        }
        swap(cur, prv);
        // Reset cur for next iteration
        for (int j = 0; j <= m; j++)
            for (int a = 0; a <= k1; a++)
                fill(cur[j][a].begin(), cur[j][a].end(), 0);
    }

    cout << prv[m][k1][k2] << endl;
    return 0;
}