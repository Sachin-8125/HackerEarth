#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int len, link, first_pos;
    int next[26];
    long long count;
    bool is_clone;

    Node() {
        len = 0;
        link = -1;
        first_pos = -1;
        count = 0;
        is_clone = false;
        for (int i = 0; i < 26; i++) next[i] = -1;
    }
};

Node st[2000005];
int sz, last;

void sam_init() {
    st[0] = Node();
    sz = 1;
    last = 0;
}

void sam_extend(int c, int pos) {
    int cur = sz++;
    st[cur] = Node();
    st[cur].len = st[last].len + 1;
    st[cur].count = 1;
    st[cur].first_pos = pos;
    int p = last;
    while (p != -1 && st[p].next[c] == -1) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            for (int i = 0; i < 26; i++) st[clone].next[i] = st[q].next[i];
            st[clone].link = st[q].link;
            st[clone].count = 0;
            st[clone].is_clone = true;
            st[clone].first_pos = st[q].first_pos;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    sam_init();
    for (int i = 0; i < s.length(); i++) sam_extend(s[i] - 'a', i);

    vector<int> nodes(sz);
    for (int i = 0; i < sz; i++) nodes[i] = i;
    sort(nodes.begin(), nodes.end(), [](int a, int b) {
        return st[a].len > st[b].len;
    });

    for (int v : nodes) {
        if (st[v].link != -1) {
            st[st[v].link].count += st[v].count;
        }
    }

    long long max_cnt = 0;
    int max_len = 0;
    int min_idx = 1e9;
    int best_state = -1;

    for (int i = 1; i < sz; i++) {
        if (st[i].count > max_cnt) {
            max_cnt = st[i].count;
            max_len = st[i].len;
            min_idx = st[i].first_pos - st[i].len + 1;
            best_state = i;
        } else if (st[i].count == max_cnt) {
            if (st[i].len > max_len) {
                max_len = st[i].len;
                min_idx = st[i].first_pos - st[i].len + 1;
                best_state = i;
            } else if (st[i].len == max_len) {
                int start_idx = st[i].first_pos - st[i].len + 1;
                if (start_idx < min_idx) {
                    min_idx = start_idx;
                    best_state = i;
                }
            }
        }
    }

    cout << s.substr(min_idx, max_len) << endl;

    return 0;
}