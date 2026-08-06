#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<long long> ratings(N);
    for (int i = 0; i < N; i++) {
        cin >> ratings[i];
    }

    sort(ratings.begin(), ratings.end());

    for (int i = 0; i < N && K > 0; i++) {
        if (ratings[i] < 0) {
            ratings[i] = -ratings[i];
            K--;
        } else {
            break;
        }
    }

    if (K > 0 && K % 2 != 0) {
        sort(ratings.begin(), ratings.end());
        ratings[0] = -ratings[0];
    }

    long long totalRating = 0;
    for (long long r : ratings) {
        totalRating += r;
    }

    cout << totalRating << endl;

    return 0;
}