#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
private:
    vector<long long> tree;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }
    
    void update(int idx, long long val) {
        for (int i = idx; i <= n; i += i & (-i)) {
            tree[i] += val;
        }
    }
    
    long long query(int idx) {
        long long sum = 0;
        for (int i = idx; i > 0; i -= i & (-i)) {
            sum += tree[i];
        }
        return sum;
    }
    
    long long rangeQuery(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        long long totalPairs = 0;
        
        // For each starting position
        for (int start = 0; start < N; start++) {
            // Coordinate compression for this subarray
            vector<int> values;
            for (int end = start; end < N; end++) {
                values.push_back(A[end]);
                values.push_back(K - A[end]);
            }
            
            sort(values.begin(), values.end());
            values.erase(unique(values.begin(), values.end()), values.end());
            
            int maxVal = values.size();
            FenwickTree ft(maxVal);
            
            // For each ending position starting from start
            for (int end = start; end < N; end++) {
                int current = A[end];
                int complement = K - current;
                
                // Find compressed indices
                int currentIdx = lower_bound(values.begin(), values.end(), current) - values.begin() + 1;
                int complementIdx = lower_bound(values.begin(), values.end(), complement) - values.begin() + 1;
                
                // Query how many complements we've seen so far
                if (binary_search(values.begin(), values.end(), complement)) {
                    totalPairs += ft.rangeQuery(complementIdx, complementIdx);
                }
                
                // Add current element to fenwick tree
                ft.update(currentIdx, 1);
            }
        }
        
        cout << totalPairs << "\n";
    }
    
    return 0;
}
