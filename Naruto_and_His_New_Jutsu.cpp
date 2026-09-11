#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        long long oddPart = N;
        while (oddPart % 2 == 0) {
            oddPart /= 2;
        }

        long long answer = 1;
        long long temp = oddPart;

        for (long long p = 3; p * p <= temp; p += 2) {
            if (temp % p == 0) {
                long long powerSum = 1;
                long long currentPower = 1;

                while (temp % p == 0) {
                    temp /= p;
                    currentPower *= p;
                    powerSum += currentPower;
                }

                answer *= powerSum;
            }
        }

        if (temp > 1) {
            answer *= (1 + temp);
        }

        cout << answer << '\n';
    }

    return 0;
}
