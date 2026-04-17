#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    long long curr_sum = 0;
    long long reqd_sum = 0;
    bool possible = true;

    for (long long i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        
        curr_sum += a;
        reqd_sum += i;
        
        if (curr_sum < reqd_sum) {
            possible = false;
        }
    }

    if (possible && curr_sum == reqd_sum) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}