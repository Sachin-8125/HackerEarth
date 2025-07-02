#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int totalSubsets = 1 << N;
    vector<int> subsetSum(totalSubsets, 0);

    for (int mask = 0; mask < totalSubsets; mask++) {
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                subsetSum[mask] += A[i];
            }
        }
    }

    double minQ = 1.0;

    for (int maskX = 1; maskX < totalSubsets; maskX++) {
        int rest = (totalSubsets - 1) ^ maskX;
        for (int maskY = rest; maskY; maskY = (maskY - 1) & rest) {
            double ratio = static_cast<double>(subsetSum[maskX]) / subsetSum[maskY];
            double Q = abs(1.0 - ratio);
            if (Q < minQ) {
                minQ = Q;
            }
        }
    }

    cout << fixed << setprecision(6) << minQ << endl;
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <limits>
std::vector<long long> A;
int N;
double minQ = 1e18;
void solve(int idx, long long sumX, long long sumY, bool hasX, bool hasY) {
if (idx == N) {
if (hasX && hasY) {
if (sumY != 0) {
double currentQ = std::fabs(1.0 - static_cast<double>(sumX) / sumY);
minQ = std::min(minQ, currentQ);
}
}
return;
}
solve(idx + 1, sumX + A[idx], sumY, true, hasY);
solve(idx + 1, sumX, sumY + A[idx], hasX, true);
solve(idx + 1, sumX, sumY, hasX, hasY);
}
int main() {
std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);
std::cin >> N;
A.resize(N);
for (int i = 0; i < N; ++i) {
std::cin >> A[i];
}
solve(0, 0, 0, false, false);
std::cout << std::fixed << std::setprecision(6) << minQ << std::endl;
return 0;
}
*/
