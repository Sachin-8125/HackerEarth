#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

void strip_cr(string& s) {
    if (!s.empty() && s.back() == '\r') {
        s.pop_back();
    }
}

void solve() {
    string A, B;
    getline(cin, A);
    strip_cr(A);
    getline(cin, B);
    strip_cr(B);

    vector<int> req(256, 0);
    int required_unique_chars = 0;

    for (char c : B) {
        if (req[(unsigned char)c] == 0) {
            required_unique_chars++;
        }
        req[(unsigned char)c]++;
    }

    if (required_unique_chars == 0) {
        cout << "-1\n";
        return;
    }

    vector<int> window_counts(256, 0);
    int formed = 0;
    int left = 0, right = 0;
    int min_len = INT_MAX;
    int min_start = 0;

    while (right < A.length()) {
        char c = A[right];
        window_counts[(unsigned char)c]++;

        if (req[(unsigned char)c] > 0 && window_counts[(unsigned char)c] == req[(unsigned char)c]) {
            formed++;
        }

        while (left <= right && formed == required_unique_chars) {

            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                min_start = left;
            }

            char l_char = A[left];
            window_counts[(unsigned char)l_char]--;
            if (req[(unsigned char)l_char] > 0 && window_counts[(unsigned char)l_char] < req[(unsigned char)l_char]) {
                formed--;
            }
            left++;
        }
        right++;
    }

    if (min_len == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << A.substr(min_start, min_len) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        string dummy;
        getline(cin, dummy);
        while (T--) {
            solve();
        }
    }
    return 0;
}