#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;  // Read input string

    for (char &c : S) {
        if (islower(c)) {
            c = toupper(c);  // Convert lowercase to uppercase
        } else if (isupper(c)) {
            c = tolower(c);  // Convert uppercase to lowercase
        }
    }

    cout << S << endl;  // Print modified string
    return 0;
}