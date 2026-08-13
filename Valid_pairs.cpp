#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long solve(int N, const vector<long long>& wealth) {
    vector<long long> powersOf3;
    long long currentPower = 1;
    powersOf3.push_back(currentPower);
    while (currentPower <= 3000000000000000000LL / 3) { // Prevention of overflow
        currentPower *= 3;
        powersOf3.push_back(currentPower);
    }

    unordered_map<long long, long long> frequencyMap;
    long long validPairsCount = 0;

    for (int i = 0; i < N; ++i) {
        long long currentWealth = wealth[i];
        
        for (long long p3 : powersOf3) {
            long long requiredTarget = p3 - currentWealth;
            if (frequencyMap.count(requiredTarget)) {
                validPairsCount += frequencyMap[requiredTarget];
            }
        }
        
        frequencyMap[currentWealth]++;
    }

    return validPairsCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (cin >> N) {
        vector<long long> wealth(N);
        for (int i = 0; i < N; ++i) {
            cin >> wealth[i];
        }
        cout << solve(N, wealth) << "\n";
    }
    return 0;
}