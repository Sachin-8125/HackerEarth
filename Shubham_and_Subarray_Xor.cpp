#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TrieNode {
    TrieNode* children[2];
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class BinaryTrie {
private:
    TrieNode* root;

public:
    BinaryTrie() {
        root = new TrieNode();
    }

    void insert(long long num) {
        TrieNode* curr = root;
        for (int i = 40; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!curr->children[bit]) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }

    long long getMaxXor(long long num) {
        TrieNode* curr = root;
        long long maxXor = 0;
        for (int i = 40; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int toggledBit = 1 - bit;

            if (curr->children[toggledBit]) {
                maxXor |= (1LL << i);
                curr = curr->children[toggledBit];
            } else if (curr->children[bit]) {
                curr = curr->children[bit];
            } else {
                break;
            }
        }
        return maxXor;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<long long>> left_sums(n);
    vector<vector<long long>> right_sums(n);

    for (int i = 0; i < n; i++) {
        long long current_sum = 0;
        for (int j = i; j >= 0; j--) {
            current_sum += a[j];
            left_sums[i].push_back(current_sum);
        }
    }

    for (int i = 0; i < n; i++) {
        long long current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += a[j];
            right_sums[i].push_back(current_sum);
        }
    }

    BinaryTrie trie;
    long long globalMaxXor = 0;

    for (int i = 0; i < n - 1; i++) {
        for (long long sum : left_sums[i]) {
            trie.insert(sum);
        }

        for (long long sum : right_sums[i + 1]) {
            long long currentXor = trie.getMaxXor(sum);
            globalMaxXor = max(globalMaxXor, currentXor);
        }
    }

    cout << globalMaxXor << "\n";

    return 0;
}