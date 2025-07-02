#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<char, int> d = {
        {'0', 6}, {'1', 2}, {'2', 5}, {'3', 5}, {'4', 4},
        {'5', 5}, {'6', 6}, {'7', 3}, {'8', 7}, {'9', 6}
    };

    int t;
    cin >> t;

    while (t--) {
        string n;
        cin >> n;

        int no_of_matchstick = 0;
        for (char c : n) {
            no_of_matchstick += d[c];
        }

        string number;
        // Case 1: Max number when the number of matchsticks is even
        if (no_of_matchstick % 2 == 0) {
            int x = no_of_matchstick / 2;
            number = string(x, '1');
        } else {
            int x = (no_of_matchstick - 3) / 2;
            number = "7" + string(x, '1');
        }

        cout << number << endl;
    }

    return 0;
}