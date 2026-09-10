#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int freq[26] = {};
    for (char c : str) {
        freq[c - 'a']++;
    }

    int n;
    cin >> n;

    while (n--) {
        string query;
        cin >> query;

        int qfreq[26] = {};
        for (char c : query) {
            qfreq[c - 'a']++;
        }

        bool possible = true;
        for (int i = 0; i < 26; ++i) {
            if (qfreq[i] > freq[i]) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }

    return 0;
}
