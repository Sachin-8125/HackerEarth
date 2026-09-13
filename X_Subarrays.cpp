#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while (t--) {
        int n; 
        long long k; 
        
        cin >> n >> k;

        vector<long long> a(n);

        for (int i = 0; i < n; ++i) cin >> a[i];

        long long ans = 0; 
        int l = 0, r = n - 1;

        while (l <= r) {
            if (a[l] + a[r] <= k) { 
                ans += (r - l + 1); 
                ++l; 
            }else{
                --r;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}