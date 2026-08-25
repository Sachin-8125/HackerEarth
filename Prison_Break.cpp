#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> grid;
vector<vector<bool>> vis;
long long total_paths;

void dfs(int r, int c) {
    if (r == n - 1 && c == n - 1) {
        total_paths++;
        return;
    }

    vis[r][c] = true;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
            if (grid[nr][nc] == 0 && !vis[nr][nc]) {
                dfs(nr, nc);
            }
        }
    }

    vis[r][c] = false;
}

void solve() {
    cin >> n;
    grid.assign(n, vector<int>(n));
    vis.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    if (n == 1 && grid[0][0] == 1) {
        cout << 0 << "\n";
        return;
    }
    
    total_paths = 0;
    dfs(0, 0); 
    
    cout << total_paths << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}