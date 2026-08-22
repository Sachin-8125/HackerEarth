#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> st;          
        st.reserve(n);

        string out;
        out.reserve(12 * n + 1);

        for (int i = 0; i < n; ++i) {
            long long s;
            cin >> s;

            while (!st.empty() && st.back() <= s)
                st.pop_back();

            st.push_back(s);

            out += to_string(st.size());
            out.push_back(i + 1 == n ? '\n' : ' ');
        }
        cout << out;
    }
    return 0;
}