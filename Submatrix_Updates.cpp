#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, m, q;
    cin >> n >> m >> q;
    
    // Initialize the matrix
    vector<vector<long long>> matrix(n, vector<long long>(m));
    
    // Read matrix elements
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Process queries
    for(int query = 0; query < q; query++) {
        long long row, col, size, delta;
        cin >> row >> col >> size >> delta;
        
        // Convert to 0-indexed and apply range update
        for(int i = row - 1; i < row + size - 1; i++) {
            for(int j = col - 1; j < col + size - 1; j++) {
                matrix[i][j] += delta;
            }
        }
    }
    
    // Output the final matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << matrix[i][j];
            if(j < m - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
