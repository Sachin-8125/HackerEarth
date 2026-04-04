#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    long long total_sum = 0;
    
    for (int i = 0; i < n; ++i) {
        vector<bool> present(n + 2, false);
        int curr_mex = 1;
        
        for (int j = i; j < n; ++j) {
            if (a[j] <= n + 1) {
                present[a[j]] = true;
            }
            while (present[curr_mex]) {
                curr_mex++; 
            }
            total_sum += curr_mex;
        }
    }
    
    cout << total_sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}