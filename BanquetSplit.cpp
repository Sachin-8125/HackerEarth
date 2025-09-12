#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<int> depth;

void dfs(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

vector<int> getPath(int u, int v) {
    vector<int> pathU, pathV;
    
    int tu = u, tv = v;
    while (depth[tu] > depth[tv]) {
        pathU.push_back(tu);
        tu = parent[tu];  
    }
    while (depth[tv] > depth[tu]) {
        pathV.push_back(tv);
        tv = parent[tv];
    }
    
    while (tu != tv) {
        pathU.push_back(tu);
        pathV.push_back(tv);
        tu = parent[tu];
        tv = parent[tv];
    }
    
    pathU.push_back(tu); // LCA
    
    vector<int> fullPath = pathU;
    reverse(pathV.begin(), pathV.end());
    fullPath.insert(fullPath.end(), pathV.begin(), pathV.end());
    
    return fullPath;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        adj.assign(n + 1, vector<int>());
        parent.assign(n + 1, -1);
        depth.assign(n + 1, 0);
        
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Root the tree at node 1
        dfs(1, -1, 0);
        
        int q;
        cin >> q;
        
        while (q--) {
            int u, v;
            cin >> u >> v;
            
            // Find path between u and v
            vector<int> path = getPath(u, v);
            int pathLength = path.size() - 1;
            
            // If path length is even, adding edge creates odd cycle
            if (pathLength % 2 == 0) {
                cout << "No\n";
                cout << "1 " << (pathLength + 1) << "\n";
            } else {
                cout << "Yes\n";
            }
        }
    }
    
    return 0;
}
