#include <iostream>

using namespace std;

const int MAX = 2000005;
int F[MAX];
long long P[MAX];
long long PP[MAX];

void precompute() {
    for (int p = 2; p < MAX; ++p) {
        if (F[p] == 0) { 
            for (int i = p; i < MAX; i += p) {
                F[i]++;
            }
        }
    }
    
    P[0] = 0;
    for (int i = 1; i < MAX; ++i) {
        P[i] = P[i - 1] + F[i];
    }
    
    PP[0] = 0;
    for (int i = 1; i < MAX; ++i) {
        PP[i] = PP[i - 1] + P[i];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    long long ans = (PP[n + m] - PP[m]) - (PP[n] - PP[0]);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}