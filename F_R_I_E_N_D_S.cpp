#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> player_names = {"Ashu", "Mishra", "Pk", "Powale"};
    vector<vector<string>> players(4);

    // Read input and distribute cards
    for (int i = 0; i < 52; ++i) {
        string suit, value;
        cin >> suit >> value;
        players[i % 4].push_back(value);
    }

    vector<string> can_throw;

    for (int i = 0; i < 4; ++i) {
        int face_count = 0;
        for (const string& card : players[i]) {
            if (card == "A" || card == "K" || card == "Q" || card == "J")
                face_count++;
        }
        if (face_count <= 1)
            can_throw.push_back(player_names[i]);
    }

    if (can_throw.empty()) {
        cout << "-1" << endl;
    } else {
        sort(can_throw.begin(), can_throw.end());
        cout << can_throw[0] << endl;
    }
    return 0;
}
