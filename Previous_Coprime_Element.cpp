#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXV = 100000;
vector<int> sq_divs[MAXV + 1];
vector<int> mu[MAXV + 1];
int min_prime[MAXV + 1];
vector<int> pos[MAXV + 1];

void precompute() {
    for (int i = 2; i <= MAXV; ++i) {
        if (min_prime[i] == 0) {
            for (int j = i; j <= MAXV; j += i) {
                if (min_prime[j] == 0) {
                    min_prime[j] = i;
                }
            }
        }
    }

    for (int i = 1; i <= MAXV; ++i) {
        vector<int> primes;
        int temp = i;
        while (temp > 1) {
            int p = min_prime[temp];
            primes.push_back(p);
            while (temp % p == 0) {
                temp /= p;
            }
        }
        
        int k = primes.size();
        for (int mask = 0; mask < (1 << k); ++mask) {
            int d = 1;
            int m = 1;
            for (int bit = 0; bit < k; ++bit) {
                if ((mask >> bit) & 1) {
                    d *= primes[bit];
                    m = -m;
                }
            }
            sq_divs[i].push_back(d);
            mu[i].push_back(m);
        }
    }
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    for (int i = 1; i <= MAXV; ++i) {
        pos[i].clear();
    }
    
    for (int i = 0; i < N; ++i) {
        int x = A[i];
        
        int L = 0, R = i - 1, ans = -1;
        while (L <= R) {
            int mid = L + (R - L) / 2;
            int count = 0;
            
            for (size_t k = 0; k < sq_divs[x].size(); ++k) {
                int d = sq_divs[x][k];
                int m = mu[x][k];
                auto it = lower_bound(pos[d].begin(), pos[d].end(), mid);
                int cnt = pos[d].end() - it;
                count += m * cnt;
            }
            
            if (count > 0) {
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        
        cout << ans << (i == N - 1 ? "" : " ");
        
        for (int d : sq_divs[x]) {
            pos[d].push_back(i);
        }
    }
    cout << "\n";
}

int main() {
    // Fast I/O
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