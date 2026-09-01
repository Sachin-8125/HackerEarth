#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct SegmentTree {
    int n;
    vector<ll> tree;
    vector<ll> lazy;
    vector<bool> hasLazy;

    SegmentTree(const vector<ll>& a) {
        n = (int)a.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        hasLazy.assign(4 * n, false);
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, const vector<ll>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void apply(int node, ll val) {
        tree[node] = val;
        lazy[node] = val;
        hasLazy[node] = true;
    }

    void push(int node) {
        if (!hasLazy[node])
            return;

        apply(node * 2, lazy[node]);
        apply(node * 2 + 1, lazy[node]);

        hasLazy[node] = false;
    }

    void update(int node, int l, int r, int ql, int qr, ll val, int xr) {
        if (qr < l || r < ql) return;

        if (ql <= l && r <= qr) {
            apply(node, val);
            return;
        }

        push(node);

        int mid = (l + r) / 2;

        int len = r - l + 1;
        int bit = __builtin_ctz(len) - 1;

        if ((xr >> bit) & 1) {
            update(node * 2 + 1, l, mid, ql, qr, val, xr);
            update(node * 2, mid + 1, r, ql, qr, val, xr);
        }else {
            update(node * 2, l, mid, ql, qr, val, xr);
            update(node * 2 + 1, mid + 1, r, ql, qr, val, xr);
        }

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    ll query(int node, int l, int r, int ql, int qr, int xr) {
        if (qr < l || r < ql) return LLONG_MIN;
        if (ql <= l && r <= qr) return tree[node];

        push(node);

        int mid = (l + r) / 2;

        int len = r - l + 1;
        int bit = __builtin_ctz(len) - 1;

        if ((xr >> bit) & 1) {
            return max(
                query(node * 2 + 1, l, mid, ql, qr, xr),
                query(node * 2, mid + 1, r, ql, qr, xr)
            );
        }else {
            return max(
                query(node * 2, l, mid, ql, qr, xr),
                query(node * 2 + 1, mid + 1, r, ql, qr, xr)
            );
        }
    }

    void update(int l, int r, ll val, int xr) {
        update(1, 0, n - 1, l, r, val, xr);
    }

    ll query(int l, int r, int xr) {
        return query(1, 0, n - 1, l, r, xr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    int N = 1 << n;

    vector<ll> a(N);
    for (auto &x : a)
        cin >> x;

    SegmentTree st(a);

    int xr = 0;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;

            cout << st.query(l, r, xr) << '\n';
        }
        else if (type == 2) {
            int l, r;
            ll v;

            cin >> l >> r >> v;

            st.update(l, r, v, xr);
        }
        else {
            int k;
            cin >> k;

            xr ^= k;
        }
    }

    return 0;
}