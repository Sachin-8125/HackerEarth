#include <bits/stdc++.h> 
using namespace std; 
int main() { 
    string s; 
    char c; 
    int n, p, cnt = 0, z = 0, idx = -1; 
    cin >> s; 
    n = (int)s.size(); 
    assert(n >= 1 && n <= 1000); 
    for ( int i = 0; i < n; i++ ) 
        assert(s[i] >= 'a' && s[i] <= 'z'); 
        cin >> c; assert(c >= 'a' && c <= 'z'); 
        cin >> p; assert(p >= 1 && p <= n); 
    for ( int i = 0; i < p; i++ ) 
        cnt += (s[i] == c); 
    z = max(z, cnt); 
    for ( int i = p; i < n; i++ ) { 
        cnt -= (s[i - p] == c); 
        cnt += (s[i] == c); 
        z = max(z, cnt); 
    } 
    if ( z == p ) { 
        puts("-1"); 
        return 0; 
    } 
    p--; 
    cnt = 0; 
    for ( int i = 0; i < p; i++ ) 
        cnt += (s[i] == c); 
    if ( cnt == z ) idx = p; 
    for ( int i = p; i < n; i++ ) { 
        cnt -= (s[i - p] == c); 
        cnt += (s[i] == c); 
        if ( cnt == z ) idx = i + 1; 
    } 
    cout << idx << endl; 
    return 0; 
}