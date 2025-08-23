#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool isValidIP(const string& S) {
    vector<string> parts;
    string part;
    stringstream ss(S);

    // Split the string by '.'
    while (getline(ss, part, '.')) {
        parts.push_back(part);
    }

    // Check for 4 parts
    if (parts.size() != 4) return false;

    for (string& p : parts) {
        // Part must not be empty
        if (p.empty()) return false;

        // No leading zeros unless the part is "0"
        if (p.size() > 1 && p[0] == '0') return false;
        
        // All digits
        for (char c : p) {
            if (!isdigit(c)) return false;
        }

        int num = stoi(p);
        if (num < 0 || num > 255) return false;
    }
    return true;
}

int main() {
    string S;
    cin >> S;
    if (isValidIP(S)) cout << "YES";
    else cout << "NO";
    return 0;
}
