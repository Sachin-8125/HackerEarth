#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to compute nCr (binomial coefficient)
double nCr(int n, int r) {
    if (r > n - r) 
        r = n - r;
    double res = 1;
    for (int i = 0; i < r; ++i) {
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int K, N;
        cin >> K >> N;
        double p = 0.6; // Gupt's probability of winning a game
        double ans = 0.0;
        for (int i = K; i <= N; ++i) {
            double comb = nCr(N, i);
            double prob = comb * pow(p, i) * pow(1 - p, N - i);
            ans += prob;
        }
        cout << fixed << setprecision(6) << ans << endl;
    }
    return 0;
}
