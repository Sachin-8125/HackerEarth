#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Query {
    int l, r, x, y, id, block;
};

class SegmentTree {
private:
    int n;
    vector<ll> tree;

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n + 5, 0);
    }

    void update(int node, int left, int right, int position, ll value) {
        if (left == right) {
            tree[node] = value;
            return;
        }

        int mid = (left + right) / 2;

        if (position <= mid) {
            update(node * 2, left, mid, position, value);
        } else {
            update(node * 2 + 1, mid + 1, right, position, value);
        }

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(int position, ll value) {
        update(1, 1, n, position, value);
    }

    ll query(int node, int left, int right, int queryLeft, int queryRight) {
        if (queryRight < left || right < queryLeft) {
            return 0;
        }

        if (queryLeft <= left && right <= queryRight) {
            return tree[node];
        }

        int mid = (left + right) / 2;

        return query(node * 2, left, mid, queryLeft, queryRight) +
               query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
    }

    ll query(int left, int right) {
        if (left > right) {
            return 0;
        }

        return query(1, 1, n, left, right);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> originalArray(N + 1);
        vector<int> compressedArray(N + 1);
        vector<int> values;

        values.reserve(N);

        for (int i = 1; i <= N; i++) {
            cin >> originalArray[i];
            values.push_back(originalArray[i]);
        }

        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        for (int i = 1; i <= N; i++) {
            compressedArray[i] =
                lower_bound(values.begin(), values.end(), originalArray[i]) -
                values.begin();
        }

        int Q;
        cin >> Q;

        int blockSize = max(1, static_cast<int>(sqrt(N)));

        vector<Query> queries(Q);

        for (int i = 0; i < Q; i++) {
            int L, R, X, Y;
            cin >> L >> R >> X >> Y;

            queries[i] = {L, R, X, Y, i, L / blockSize};
        }

        sort(queries.begin(), queries.end(), [&](const Query& a, const Query& b) {
            if (a.block != b.block) {
                return a.block < b.block;
            }

            if (a.block & 1) {
                return a.r > b.r;
            }

            return a.r < b.r;
        });

        vector<int> frequency(values.size(), 0);

        vector<ll> xorAtFrequency(N + 1, 0);

        SegmentTree segmentTree(N);

        auto updateFrequency = [&](int compressedValue, int delta) {
            int oldFrequency = frequency[compressedValue];
            int newFrequency = oldFrequency + delta;
            ll value = values[compressedValue];

            if (oldFrequency > 0) {
                xorAtFrequency[oldFrequency] ^= value;
                segmentTree.update(
                    oldFrequency,
                    xorAtFrequency[oldFrequency]
                );
            }

            frequency[compressedValue] = newFrequency;

            if (newFrequency > 0) {
                xorAtFrequency[newFrequency] ^= value;
                segmentTree.update(
                    newFrequency,
                    xorAtFrequency[newFrequency]
                );
            }
        };

        int currentLeft = 1;
        int currentRight = 0;

        vector<ll> answers(Q);

        for (const Query& query : queries) {
            while (currentLeft > query.l) {
                --currentLeft;
                updateFrequency(compressedArray[currentLeft], +1);
            }

            while (currentRight < query.r) {
                ++currentRight;
                updateFrequency(compressedArray[currentRight], +1);
            }

            while (currentLeft < query.l) {
                updateFrequency(compressedArray[currentLeft], -1);
                ++currentLeft;
            }

            while (currentRight > query.r) {
                updateFrequency(compressedArray[currentRight], -1);
                --currentRight;
            }

            answers[query.id] = segmentTree.query(query.x, query.y);
        }

        for (ll answer : answers) {
            cout << answer << '\n';
        }
    }

    return 0;
}
