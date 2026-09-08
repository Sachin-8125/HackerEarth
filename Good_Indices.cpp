#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> L(n, -1);
    stack<int> st_left;
    
    for (int i = 0; i < n; ++i) {
        while (!st_left.empty() && a[st_left.top()] >= a[i]) {
            st_left.pop();
        }
        if (!st_left.empty()) {
            L[i] = st_left.top();
        }
        st_left.push(i);
    }
    
    vector<int> R(n, -1);
    stack<int> st_right;
    
    for (int i = n - 1; i >= 0; --i) {
        while (!st_right.empty() && a[st_right.top()] >= a[i]) {
            st_right.pop();
        }
        if (!st_right.empty()) {
            R[i] = st_right.top();
        }
        st_right.push(i);
    }
    
    for (int i = 0; i < n; ++i) {
        if (L[i] == -1 || R[i] == -1) {
            cout << -1 << (i == n - 1 ? "" : " ");
        } else {
            int operations = R[i] - L[i] - 2;
            cout << operations << (i == n - 1 ? "" : " ");
        }
    }
    cout << "\n";
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