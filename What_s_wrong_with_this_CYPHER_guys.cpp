#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Disjoint Set Union with path compression and union by rank
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void join(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        DSU dsu(n);

        int yes = 0, no = 0;

        for (int i = 0; i < q; ++i) {
            char type;
            int x, y;
            cin >> type >> x >> y;

            if (type == 'J') {
                dsu.join(x, y);
            } else if (type == '?') {
                dsu.connected(x,y) ? yes++ : no++;
            }
        }
        cout << yes << " " << no << "\n";
    }

    return 0;
}
