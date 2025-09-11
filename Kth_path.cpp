#include <bits/stdc++.h>
using namespace std;

static const int MAX = 2005; 
long long C[MAX][MAX];

void buildComb(int lim) {
    for (int i = 0; i <= lim; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = min(C[i-1][j-1] + C[i-1][j], (long long)1e18);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<string> mat(N);
    for (int i = 0; i < N; ++i)
        cin >> mat[i];

    long long K;
    cin >> K;

    buildComb(N + M);

    int i = 0, j = 0;
    string answer;
    answer.push_back(mat[0][0]);

    while (i < N-1 || j < M-1) {
        vector<tuple<char,int,int>> moves;
        if (j+1 < M) moves.emplace_back(mat[i][j+1], i, j+1);
        if (i+1 < N) moves.emplace_back(mat[i+1][j], i+1, j);
        sort(moves.begin(), moves.end());
        auto [ch1, ni1, nj1] = moves[0];
        int down = N-1 - ni1;
        int right= M-1 - nj1;
        long long cnt = C[down+right][down];

        if (K <= cnt) {
            i = ni1; j = nj1;
            answer.push_back(ch1);
        } else {
            K -= cnt;
            auto [ch2, ni2, nj2] = moves[1];
            i = ni2; j = nj2;
            answer.push_back(ch2);
        }
    }
    if (K > 1) {
        cout << "-1\n";
    } else {
        cout << answer << "\n";
    }

    return 0;
}
