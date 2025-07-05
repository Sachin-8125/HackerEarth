#include <iostream>
#include <string>
using namespace std;
int main() {
    string number;
    cin >> number;
    int k;
    cin >> k;
    while (k > 0) {
        bool digitRemoved = false;
        for (size_t i = 0; i < number.size() - 1; i++) {
            int curr = number[i] - '0';
            int next = number[i + 1] - '0';
            if (curr < next) {
                number.erase(number.begin() + i);
                digitRemoved = true;
                break;
            }
        }
        if (!digitRemoved) {
            number.erase(number.end() - 1);
        }
        k--;
    }
    cout << number << endl;
    return 0;
}