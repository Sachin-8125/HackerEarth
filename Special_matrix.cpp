#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000005;
int f[MAX];
long long sum_f[MAX];
int prime[MAX];

void precompute() {
    vector<bool> is_prime(MAX, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int p = 2; p < MAX; ++p) {
        if (is_prime[p]) {
            for (int i = p; i < MAX; i += p) {
                f[i]++;
                if (i > p) is_prime[i] = false;
            }
        }
    }
    
    for (int i = 1; i < MAX; ++i) {
        sum_f[i] = sum_f[i - 1] + f[i];
        prime[i] = prime[i - 1] + (is_prime[i] ? 1 : 0);
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    
    long long ans = 1LL * M * sum_f[N] + 1LL * N * sum_f[M];
    int limit = min(N, M);
    long long sub = 0;
    
    for (int l = 1, r; l <= limit; l = r + 1) {
        int valN = N / l;
        int valM = M / l;
        r = min({limit, N / valN, M / valM});
        
        int primes_in_range = prime[r] - prime[l - 1];
        sub += 1LL * primes_in_range * valN * valM;
    }
    
    cout << ans - sub << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    
    return 0;
}