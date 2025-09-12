#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> chessboard(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> chessboard[i][j];
        }
    }

    int maxSum = 0;
    int row = -1;
    int col = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;

            // Calculate the sum of cells under attack by the rook in horizontal direction
            for (int k = 0; k < m; k++) {
                if (k != j) {
                    sum += chessboard[i][k];
                }
            }

            // Calculate the sum of cells under attack by the rook in vertical direction
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    sum += chessboard[k][j];
                }
            }

            // Update maxSum and position if the current sum is greater
            if (sum > maxSum || (sum == maxSum && (row == -1 || i < row || (i == row && j < col)))) {
                maxSum = sum;
                row = i;
                col = j;
            }
        }
    }

    cout << row + 1 << " " << col + 1 << "\n"; // Convert to 1-based indexing
    return 0;
}
