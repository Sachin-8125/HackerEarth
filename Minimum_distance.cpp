#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

void update(vector<long long>& A, int N, int ID, int VAL) {
    if (VAL == 0) {
        return;
    }
    
    A[ID] = A[ID] + VAL;
    
    if (ID == N) {
        update(A, N, 1, VAL - 1);
    } else {
        update(A, N, ID + 1, VAL - 1);
    }
}

long long query(vector<long long>& A, int N, int L, int R) {
    if (L == R) {
        return A[L];
    }
    
    if (L == N) {
        return (A[L] + query(A, N, 1, R)) % MOD;
    } else {
        return (A[L] + query(A, N, L + 1, R)) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<long long> A(N + 1); // 1-based indexing
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            // UPDATE query
            int ID, VAL;
            cin >> ID >> VAL;
            update(A, N, ID, VAL);
        } else {
            // QUERY query
            int L, R;
            cin >> L >> R;
            long long result = query(A, N, L, R);
            cout << result << "\n";
        }
    }
    
    return 0;
}
