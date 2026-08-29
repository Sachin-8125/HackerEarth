#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        char min_char = *min_element(s.begin(), s.end());
        cout << min_char << "\n";
    }

    return 0;
}