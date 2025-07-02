#include <bits/stdc++.h>

using namespace std;
#define int long long int

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> zero(n, 0), one(n, 0);
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            zero[i] = 1;
        }
        if(a[i] == 1) {
            one[i] = 1;
        }
        if(i > 0) {
            zero[i] += zero[i - 1];
            one[i] += one[i - 1];
        }
    }
    
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l = l - 1;
        r = r - 1;
        
        int x = zero[r];
        if(l > 0) {
            x = x - zero[l - 1];
        }
        
        int y = one[r];
        if(l > 0) {
            y = y - one[l - 1];
        }
        
        int len = r - l + 1;
        int c = (len * (len - 1)) / 2;
        c = c - (x * (x - 1)) / 2 - (x * y);
        cout << c << endl;
    }
}

#undef int
int main() {
    #define int long long int
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}