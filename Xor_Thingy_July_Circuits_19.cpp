#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 519, Mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    int dp[N]{}, tdp[N]{};
    dp[0] = 1;
    while (n--) {
        int a;
        cin >> a;
        memset(tdp, 0, sizeof tdp);
        for (int i = 0; i <= a; ++i)
            for (int j = 0; j < 512; ++j) {
                tdp[i ^ j] += dp[j];
                if (tdp[i ^ j] >= Mod) tdp[i ^ j] -= Mod;
            }
        memcpy(dp, tdp, sizeof dp);
    }
    for (int i = 0; i <= m; ++i)
        cout << dp[i] << ' ';
    cout << '\n';
}
