#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    // Read number of test cases
    ll t;
    cin >> t;
    
    while(t--) {
        // Input array size and constraints
        ll n, x, y;
        cin >> n >> x >> y;
        
        // Input array elements
        vector<ll> a(n);
        for(ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Initialize sliding window variables
        ll l = 0, r = 0;
        unordered_map<ll, ll> mp;
        ll cnt = 0, maxi = 0;
        bool flag = false;
        
        // Process array using sliding window technique
        while(r < n) {
            // Add right element to window
            if(mp[a[r]] == 0) {
                cnt++;
            }
            
            // Shrink window if unique elements exceed x
            while(cnt > x) {
                mp[a[l]]--;
                if(mp[a[l]] == 0) cnt--;
                if(a[l] == y && mp[a[l]] == 0) flag = false;
                l++;
            }
            
            // Check if y is present in current window
            if(a[r] == y) flag = true;
            
            // Update maximum window size if conditions met
            if(cnt == x && flag == true) {
                maxi = max(maxi, r - l + 1);
            }
            
            mp[a[r]]++;
            r++;
        }
        
        cout << maxi << endl;
    }
    
    return 0;
}