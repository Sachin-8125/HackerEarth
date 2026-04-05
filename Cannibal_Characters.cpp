#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Minimum_Operations(int n, string s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    int operations = 0;
    for (int i = 0; i < 26; i++) {
        operations += freq[i] / 2;
    }

    return operations;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        cout << Minimum_Operations(n, s) << "\n";
    }
    return 0;
}