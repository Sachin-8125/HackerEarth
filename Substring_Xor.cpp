#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int BITS = 20;

struct TrieNode {
    int child[2];
    int cnt;

    TrieNode() {
        child[0] = child[1] = -1;
        cnt = 0;
    }
};

struct BinaryTrie {
    vector<TrieNode> trie;

    BinaryTrie(int reserveSize = 0) {
        if (reserveSize)
            trie.reserve(reserveSize);
        trie.emplace_back();
    }

    void clear() {
        trie.clear();
        trie.emplace_back();
    }

    void insert(int x) {
        int node = 0;
        trie[node].cnt++;

        for (int b = BITS - 1; b >= 0; --b) {
            int bit = (x >> b) & 1;

            if (trie[node].child[bit] == -1) {
                trie[node].child[bit] = (int)trie.size();
                trie.emplace_back();
            }

            node = trie[node].child[bit];
            trie[node].cnt++;
        }
    }

    ll countGreaterEqual(int x, int k) {
        int node = 0;
        ll ans = 0;

        for (int b = BITS - 1; b >= 0 && node != -1; --b) {
            int xb = (x >> b) & 1;
            int kb = (k >> b) & 1;

            if (kb == 0) {
                int greaterChild = trie[node].child[xb ^ 1];

                if (greaterChild != -1)
                    ans += trie[greaterChild].cnt;

                node = trie[node].child[xb];
            } 
            else {
                node = trie[node].child[xb ^ 1];
            }
        }

        if (node != -1)
            ans += trie[node].cnt;

        return ans;
    }
};

ll countSubarrays(int a[], int n, int x) {
    BinaryTrie bt((n + 1) * (BITS + 1));

    ll ans = 0;
    int prefixXor = 0;

    bt.insert(0);

    for (int i = 0; i < n; ++i) {
        prefixXor ^= a[i];

        ans += bt.countGreaterEqual(prefixXor, x);

        bt.insert(prefixXor);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k;

    cin >> n >> k;

    int *a = new int[n];

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int low = 0;
    int high = (1 << BITS) - 1;

    while (low < high) {
        int mid = low + (high - low + 1) / 2;

        if (countSubarrays(a, n, mid) >= k) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << low << '\n';

    delete[] a;

    return 0;
}