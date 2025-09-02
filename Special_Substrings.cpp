#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;
    string S;
    cin >> S;

    long long result = 0;
    unordered_map<long long, long long> prev, curr;

    for (int i = 0; i < N; i++) {
        curr.clear();
        int digit = S[i] - '0';
        long long rem = digit % M;
        curr[rem]++;
        for (auto &p : prev) {
            long long new_rem = (p.first * 10 + digit) % M;
            curr[new_rem] += p.second;
        }
        for (auto &p : curr) {
            if (__gcd(p.first, M) == 1) {
                result += p.second;
            }
        }
        prev = curr;
    }
    cout << result << "\n";
    return 0;
}
