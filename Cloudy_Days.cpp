#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(dist[u] >= k) continue; 
        for(int v : adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] != -1 && dist[i] <= k)
            ans++;
    }
    
    cout << ans << endl;
    return 0;
}