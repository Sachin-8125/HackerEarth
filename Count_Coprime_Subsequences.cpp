#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_VAL = 100000;

int mu[MAX_VAL + 5];
int pr[MAX_VAL + 5];
bool is_prime[MAX_VAL + 5];
vector<int> divisors[MAX_VAL + 5];
long long G[MAX_VAL + 5];

void precompute() {
    fill(is_prime, is_prime + MAX_VAL + 1, true);
    is_prime[0] = is_prime[1] = false;
    mu[1] = 1;
    int cnt = 0;

    for (int i = 2; i <= MAX_VAL; ++i) {
        if (is_prime[i]) {
            pr[cnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < cnt && i * pr[j] <= MAX_VAL; ++j) {
            is_prime[i * pr[j]] = false;
            if (i % pr[j] == 0) {
                mu[i * pr[j]] = 0;
                break;
            } else {
                mu[i * pr[j]] = -mu[i];
            }
        }
    }

    for (int i = 1; i <= MAX_VAL; ++i) {
        for (int j = i; j <= MAX_VAL; j += i) {
            divisors[j].push_back(i);
        }
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    fill(G, G + MAX_VAL + 1, 0);

    long long total_subsequences = 0;

    for (int i = 0; i < n; ++i) {
        int x = arr[i];
        long long ways = 1;

        for (int d : divisors[x]) {
            if (mu[d] == 1) {
                ways = (ways + G[d]) % MOD;
            } else if (mu[d] == -1) {
                ways = (ways - G[d] + MOD) % MOD;
            }
        }

        total_subsequences = (total_subsequences + ways) % MOD;

        for (int d : divisors[x]) {
            G[d] = (G[d] + ways) % MOD;
        }
    }

    cout << total_subsequences << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}