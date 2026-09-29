#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string A, B;
        int K;

        cin >> A >> B >> K;

        vector<int> frequency(26, 0);

        for (char c : A) {
            frequency[c - 'a']++;
        }

        for (char c : B) {
            frequency[c - 'a']++;
        }

        long long answer = LLONG_MAX;

        for (int start = 0; start < 26; start++) {
            long long cost = 0;

            for (int character = 0; character < 26; character++) {
                int clockwiseDistance = (character - start + 26) % 26;

                if (clockwiseDistance <= K) {
                    continue;
                }

                int distanceToRightEnd = clockwiseDistance - K;

                int distanceToLeftEnd = 26 - clockwiseDistance;

                cost += 1LL * frequency[character] * min(distanceToRightEnd, distanceToLeftEnd);
            }

            answer = min(answer, cost);
        }

        cout << answer << '\n';
    }

    return 0;
}