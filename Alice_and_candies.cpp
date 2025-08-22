#include <iostream>
using namespace std;

// Function to check if (a, b) can form a valid pair
bool valid_pair(int a, int b) {
    int n2 = (a + b) / 2;
    int n1 = (a - b) / 2;

    return (n2 >= 0 && n1 >= 0 && n2 >= n1);
}

int main() {
    int n;
    cin >> n;

    int ans = 0;

    // Iterate over all divisors of n
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            int a = i;
            int b = n / i;

            // Only proceed if a and b have the same parity (both even or both odd)
            if ((a % 2 == b % 2)) {
                if (valid_pair(a, b)) {
                    ans++;
                }
                // Avoid duplicate check when a == b
                if (i * i != n && valid_pair(b, a)) {
                    ans++;
                }
            }
        }
    }

    cout << ans;
    return 0;
}
