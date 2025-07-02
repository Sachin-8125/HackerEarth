#include <iostream>
#include <string>

using namespace std;

void solve(string s) {
    int charCount [26] = {0};

    for (char ch : s) {
        charCount[ch - 'a']++;
    }

    int result = 0;
    for (int count : charCount) {
        result += count / 2;
    }

    cout << result << endl;
}

int main() {
    int testCases;
    cin >> testCases;

    for (int testCase = 0; testCase < testCases; testCase++) {
        string input;
        cin >> input;
        solve(input);
    }

    return 0;
}