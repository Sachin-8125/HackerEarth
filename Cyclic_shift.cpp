#include <bits/stdc++.h>
using namespace std;

// Booth's algorithm variant to find index of lexicographically maximum rotation
int max_rotation_index(const string &s) {
    int n = (int)s.size();
    string ss = s + s;
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        char a = ss[i + k], b = ss[j + k];
        if (a == b) {
            ++k;
        } else if (a < b) {
            i = i + k + 1;
            if (i == j) ++i;
            k = 0;
        } else { // a > b -> j is worse
            j = j + k + 1;
            if (i == j) ++j;
            k = 0;
        }
    }
    return min(i, j);
}

// KMP prefix function
vector<int> prefix_function(const string &s) {
    int n = (int)s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

// Find all starting positions where pattern p occurs in text t using KMP
vector<int> kmp_find_all(const string &t, const string &p) {
    vector<int> pi = prefix_function(p);
    vector<int> res;
    int j = 0;
    for (int i = 0; i < (int)t.size(); ++i) {
        while (j > 0 && t[i] != p[j]) j = pi[j-1];
        if (t[i] == p[j]) ++j;
        if (j == (int)p.size()) {
            res.push_back(i - (int)p.size() + 1);
            j = pi[j-1];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long N, K;
        string A;
        cin >> N >> K;
        cin >> A;
        
        // Edge case: all chars equal
        bool all_same = true;
        for (char c : A) if (c != A[0]) { all_same = false; break; }
        if (all_same) {
            // Every rotation equals B; K-th time at shifts = K-1
            cout << (K - 1) << "\n";
            continue;
        }
        
        // Find maximum rotation B
        int idx = max_rotation_index(A);
        string B = A.substr(idx) + A.substr(0, idx);
        
        // Minimal period of B
        vector<int> piB = prefix_function(B);
        int per = (int)B.size() - piB.back();
        if ((int)B.size() % per != 0) per = (int)B.size(); // not periodic
        
        // Find positions r in [0..N-1] such that rotate(A, r) == B
        // rotate(A, r) means A[r..N-1] + A[0..r-1], which appears as a substring of A+A at position r
        string AA = A + A;
        vector<int> occ = kmp_find_all(AA, B);
        vector<int> R;
        R.reserve(occ.size());
        for (int pos : occ) {
            if (0 <= pos && pos < (int)N) R.push_back(pos);
        }
        sort(R.begin(), R.end());
        // Deduplicate in rare cases (shouldn't be necessary, but safe)
        R.erase(unique(R.begin(), R.end()), R.end());
        
        // m occurrences per cycle
        long long m = (long long)R.size();
        // Safety: if none found (should not happen), fallback
        if (m == 0) {
            cout << -1 << "\n";
            continue;
        }
        
        // K-th time:
        long long q = (K - 1) / m;
        long long t = (K - 1) % m;
        long long ans = q * N + R[(size_t)t];
        cout << ans << "\n";
    }
    return 0;
}
