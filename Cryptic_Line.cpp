#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000;

// Global variables for graph traversal
vector<vector<int>> adj;
vector<bool> vis;
vector<int> en, ex;
int t = 0;

// DFS function to calculate entry and exit times
void dfs(int s) {
    vis[s] = 1;
    en[s] = ++t;
    
    for(auto it : adj[s]) {
        if(vis[it] == 0) {
            dfs(it);
        }
    }
    
    ex[s] = ++t;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    // Initialize vectors with appropriate sizes
    adj.resize(n + 1, vector<int>());
    vis.resize(n + 1, false);
    en.resize(n + 1, 0);
    ex.resize(n + 1, 0);
    
    // Build the tree
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Run DFS from root (node 1)
    dfs(1);
    
    // Process queries
    while(q--) {
        int x, y;
        cin >> x >> y;
        
        // Check if x is an ancestor of y using entry and exit times
        if(en[x] < en[y] && ex[x] > ex[y]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}