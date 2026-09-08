#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int N, P;
    cin >> N >> P;
    
    int ans = INT_MAX;
    
    for (int p = 1; p <= N + P; p++) {
        int rem = N % p;
        int choco_cost = min(rem, p - rem);
        int bucket_cost = abs(p - P);
        ans = min(ans, choco_cost + bucket_cost);
    }
    
    cout << ans << endl;
    return 0;
}