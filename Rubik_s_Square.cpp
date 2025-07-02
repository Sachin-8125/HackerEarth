#include <iostream>
#include <vector>
using namespace std;

void rotateRowRight(vector<int>& row) {
    int n = row.size();
    int last = row[n - 1];
    for (int i = n - 1; i > 0; --i)
        row[i] = row[i - 1];
    row[0] = last;
}

void rotateColumnDown(vector<vector<int>>& matrix, int colIndex) {
    int n = matrix.size();
    int last = matrix[n - 1][colIndex];
    for (int i = n - 1; i > 0; --i)
        matrix[i][colIndex] = matrix[i - 1][colIndex];
    matrix[0][colIndex] = last;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, R, C;
    cin >> N >> R >> C;

    vector<vector<int>> matrix(N, vector<int>(N));

    // Input matrix
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> matrix[i][j];

    // Read row indices to rotate (1-based indexing)
    vector<int> rowIndices(R);
    for (int i = 0; i < R; ++i) {
        cin >> rowIndices[i];
        rowIndices[i]--; // Convert to 0-based index
    }

    // Read column indices to rotate (1-based indexing)
    vector<int> colIndices(C);
    for (int i = 0; i < C; ++i) {
        cin >> colIndices[i];
        colIndices[i]--; // Convert to 0-based index
    }

    // Rotate specified rows
    for (int row : rowIndices)
        rotateRowRight(matrix[row]);

    // Rotate specified columns
    for (int col : colIndices)
        rotateColumnDown(matrix, col);

    // Output the final matrix
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
