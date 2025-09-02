#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n == 1) {
        cout << 1 << " " << 1 << "\n";
        return 0;
    }

    // Build parent and order (BFS/DFS tree)
    vector<int> parent(n + 1, 0), order;
    order.reserve(n);
    parent[1] = -1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        order.push_back(v);
        for (int u : adj[v]) if (u != parent[v]) {
            parent[u] = v;
            q.push(u);
        }
    }

    // down[v]: max edges from v going into its subtree
    // downCnt[v]: number of farthest nodes achieving down[v]
    vector<int> down(n + 1, 0);
    vector<unsigned long long> downCnt(n + 1, 1);
    for (int i = n - 1; i >= 0; --i) {
        int v = order[i];
        int best = 0;
        unsigned long long ways = 1; // if leaf: stay at v
        bool first = true;
        best = 0; ways = 1;
        // combine children
        int mx = 0;
        unsigned long long cnt = 1; // default: v itself
        mx = 0; cnt = 1;
        bool hadChild = false;
        int bestDist = 0;
        unsigned long long bestCnt = 1;
        bestDist = 0; bestCnt = 1;
        // Actually compute proper down[v]
        int curBest = 0;
        unsigned long long curCnt = 1;
        curBest = 0; curCnt = 1;
        // reset: down[v]=0, downCnt[v]=1 initially
        int d = 0; unsigned long long c = 1;
        d = 0; c = 1;
        for (int u : adj[v]) if (u != parent[v]) {
            int cand = down[u] + 1;
            if (cand > d) {
                d = cand;
                c = downCnt[u];
            } else if (cand == d) {
                c += downCnt[u];
            }
        }
        down[v] = d;
        downCnt[v] = c;
    }

    // up[v]: max edges from v going outside its subtree
    // upCnt[v]: number of nodes achieving up[v]
    vector<int> up(n + 1, 0);
    vector<unsigned long long> upCnt(n + 1, 1); // for root: 0 distance, 1 way (v itself)
    for (int v : order) {
        // Gather top1/top2 among children of v for cand = down[child] + 1
        int top1 = -1, top2 = -1;
        unsigned long long sumWaysTop1 = 0, sumWaysTop2 = 0;
        int cntBranchesTop1 = 0;
        for (int u : adj[v]) if (u != parent[v]) {
            int cand = down[u] + 1;
            unsigned long long w = downCnt[u];
            if (cand > top1) {
                top2 = top1; sumWaysTop2 = sumWaysTop1;
                top1 = cand; sumWaysTop1 = w; cntBranchesTop1 = 1;
            } else if (cand == top1) {
                sumWaysTop1 += w; cntBranchesTop1++;
            } else if (cand > top2) {
                top2 = cand; sumWaysTop2 = w;
            } else if (cand == top2) {
                sumWaysTop2 += w;
            }
        }
        // Push up to children
        for (int u : adj[v]) if (u != parent[v]) {
            int cand = down[u] + 1;
            unsigned long long w = downCnt[u];

            // Best among siblings (and possibly none -> 0 with 1 way)
            int bestSibDist = 0;
            unsigned long long bestSibCnt = 1;

            if (cand == top1) {
                // exclude u from top1
                unsigned long long remWaysTop1 = sumWaysTop1 - w;
                int remCntTop1 = cntBranchesTop1 - 1;
                if (remCntTop1 > 0) {
                    bestSibDist = top1;
                    bestSibCnt = remWaysTop1;
                } else if (top2 >= 0) {
                    bestSibDist = top2;
                    bestSibCnt = sumWaysTop2;
                } // else keep 0,1
            } else {
                if (top1 >= 0) {
                    bestSibDist = top1;
                    bestSibCnt = sumWaysTop1;
                } // else keep 0,1
            }

            // Two options to go outside u's subtree via v:
            // 1) go to parent side: 1 + up[v]
            // 2) go to a sibling subtree: 1 + bestSibDist
            int opt1 = 1 + up[v];
            unsigned long long cnt1 = upCnt[v];
            int opt2 = 1 + bestSibDist;
            unsigned long long cnt2 = bestSibCnt;

            if (opt1 > opt2) {
                up[u] = opt1;
                upCnt[u] = cnt1;
            } else if (opt2 > opt1) {
                up[u] = opt2;
                upCnt[u] = cnt2;
            } else {
                up[u] = opt1;
                upCnt[u] = cnt1 + cnt2;
            }
        }
    }

    // For each node, combine branches: parent side up[v], each child side (down[child]+1), and virtual (0,1).
    // Compute max edges sum over two distinct branches and number of pairs achieving it.
    vector<long long> ansLen(n + 1, 1);
    vector<unsigned long long> ansCnt(n + 1, 1);

    for (int v = 1; v <= n; ++v) {
        // Collect branches
        // Use streaming computation of top1/top2 and multiplicities for pairs counting
        int bTop1 = -1, bTop2 = -1;
        unsigned long long bSum1 = 0, bSum1Sq = 0, bSum2 = 0;
        int bCntBranchesTop1 = 0;

        auto consider = [&](int d, unsigned long long w) {
            if (d > bTop1) {
                bTop2 = bTop1; bSum2 = bSum1;
                bTop1 = d; bSum1 = w; bSum1Sq = w * w; bCntBranchesTop1 = 1;
            } else if (d == bTop1) {
                bSum1 += w;
                bSum1Sq += w * w;
                bCntBranchesTop1++;
            } else if (d > bTop2) {
                bTop2 = d; bSum2 = w;
            } else if (d == bTop2) {
                bSum2 += w;
            }
        };

        // Parent side
        consider(up[v], upCnt[v]);
        // Child sides
        for (int u : adj[v]) if (u != parent[v]) {
            consider(down[u] + 1, downCnt[u]);
        }
        // Virtual branch (stop at v)
        consider(0, 1);

        long long maxEdges = 0;
        unsigned long long totalWaysPairs = 0;
        if (bCntBranchesTop1 >= 2) {
            // Two branches with same top distance
            maxEdges = 1LL * bTop1 + bTop1;
            // sum over unordered pairs of branches at top1: ( (sum w)^2 - sum w^2 ) / 2
            unsigned long long s = bSum1;
            unsigned long long s2 = bSum1Sq;
            totalWaysPairs = (s * s - s2) / 2ULL;
        } else {
            // Top pair uses top1 and top2
            maxEdges = 1LL * bTop1 + bTop2;
            totalWaysPairs = bSum1 * bSum2;
        }
        ansLen[v] = maxEdges + 1;            // convert edges -> vertices
        ansCnt[v] = totalWaysPairs;
    }

    for (int v = 1; v <= n; ++v) {
        cout << ansLen[v] << " " << ansCnt[v] << "\n";
    }
    return 0;
}
