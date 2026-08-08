#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

struct Node {
    int nxt[2];
    int z;          // number of 0's in this prefix
    int f;          // number of special subarrays in this prefix
    Node() {
        nxt[0] = nxt[1] = -1;
        z = f = 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if(!(cin >> N)) return 0;
    vector<string> arr(N);
    int total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        total += (int)arr[i].size();
    }

    vector<Node> trie;
    trie.reserve(total + 5);
    trie.emplace_back(); // root at 0

    long long ans = 0;

    for (string &s : arr) {
        int v = 0;
        for (char c : s) {
            int ch = c - '0';
            if (trie[v].nxt[ch] == -1) {
                int u = (int)trie.size();
                trie[v].nxt[ch] = u;
                trie.emplace_back();
                
                int parent_z = trie[v].z;
                int parent_f = trie[v].f;
                
                trie[u].z = parent_z + (ch == 0 ? 1 : 0);
                trie[u].f = parent_f + (ch == 0 && parent_z > 0 ? 1 : 0);
                
                ans += trie[u].f;
                if (ans >= MOD) ans -= MOD;
            }
            v = trie[v].nxt[ch];
        }
    }

    cout << ans % MOD << "\n";
    return 0;
}