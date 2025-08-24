#include <iostream>
#include <string>
using namespace std;

int getShift(const string& S, const string& T) {
    int n = S.size();
    int shift = (T[0] - S[0] + 26) % 26;

    for (int i = 1; i < n; ++i) {
        int cur_shift = (T[i] - S[i] + 26) % 26;
        if (cur_shift != shift)
            return -1;
    }
    return shift;
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        string S, T;
        cin >> S >> T;
        if (S.size() != T.size()) {
            cout << -1 << endl;
            continue;
        }
        cout << getShift(S, T) << endl;
    }
    return 0;
}