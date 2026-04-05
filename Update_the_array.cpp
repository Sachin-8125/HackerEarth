#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minUpdates(int N, vector<int>& A, int K) {
    if (N % 2 != 0) {
        return -1;
    }
    
    vector<int> odds, evens;
    for (int x : A) {
        if (x % 2 != 0) {
            odds.push_back(x);
        } else {
            evens.push_back(x);
        }
    }
    
    sort(odds.begin(), odds.end());
    odds.erase(unique(odds.begin(), odds.end()), odds.end());
    
    sort(evens.begin(), evens.end());
    evens.erase(unique(evens.begin(), evens.end()), evens.end());
    
    int odds_gt_K = 0;
    for (int x : odds) {
        if (x > K) {
            odds_gt_K++;
        }
    }
    
    int evens_gt_K = 0;
    for (int x : evens) {
        if (x > K) {
            evens_gt_K++;
        }
    }
    
    int max_possible_odds = (K + 1) / 2 + odds_gt_K;
    int max_possible_evens = K / 2 + evens_gt_K;
    
    int req = N / 2;
    
    if (max_possible_odds < req || max_possible_evens < req) {
        return -1;
    }
    
    int keep_odds = min((int)odds.size(), req);
    int keep_evens = min((int)evens.size(), req);
    
    return N - (keep_odds + keep_evens);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            int N;
            cin >> N;
            vector<int> A(N);
            for (int i = 0; i < N; i++) {
                cin >> A[i];
            }
            int K;
            cin >> K;
            
            cout << minUpdates(N, A, K) << "\n";
        }
    }
    
    return 0;
}