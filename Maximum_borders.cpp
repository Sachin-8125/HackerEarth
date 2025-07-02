#include <bits/stdc++.h>
using namespace std;

// Directions for adjacent cells (up, right, down, left)
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(vector<string>& grid, vector<vector<bool>>& visited, int r, int c, int n, int m, 
         vector<pair<int,int>>& current_shape) {
    visited[r][c] = true;
    current_shape.push_back({r, c});
    for(int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
           !visited[nr][nc] && grid[nr][nc] == '#') {
            dfs(grid, visited, nr, nc, n, m, current_shape);
        }
    }
}
int getMaxBorder(vector<pair<int,int>>& shape, int n, int m) {
    // For each row and column, find max consecutive cells in the shape
    vector<vector<int>> grid(n, vector<int>(m, 0));
    // Mark shape cells
    for(auto& p : shape) {
        grid[p.first][p.second] = 1;
    }
    int max_border = 0;
    // Check each row
    for(int i = 0; i < n; i++) {
        int current = 0;
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                current++;
                max_border = max(max_border, current);
            } else {
                current = 0;
            }
        }
    }
    // Check each column
    for(int j = 0; j < m; j++) {
        int current = 0;
        for(int i = 0; i < n; i++) {
            if(grid[i][j] == 1) {
                current++;
                max_border = max(max_border, current);
            } else {
                current = 0;
            }
        }
    }
    return max_border;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for(int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int max_border = 0;
        // Find all shapes and their max borders
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '#' && !visited[i][j]) {
                    vector<pair<int,int>> current_shape;
                    dfs(grid, visited, i, j, n, m, current_shape);
                    max_border = max(max_border, getMaxBorder(current_shape, n, m));
                }
            }
        }
        cout << max_border << "\n";
    }
    return 0;
}