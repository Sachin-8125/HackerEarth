#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
long long int power(long long int number) {
    long long int ans = 1;
    long long int base = 2;
    base = base % MOD;
    while (number > 0) {
        if (number & 1) {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        number = number >> 1;
    }
    return ans;
}

int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int num;
        cin >> num;
        long long int result = power(num);
        cout << result - 1 << endl;
    }
    return 0;
}