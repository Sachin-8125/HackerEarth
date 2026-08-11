#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

static ull splitmix64(ull x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> values = a;
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    int m = values.size();
    vector<int> id(n);

    for (int i = 0; i < n; i++) {
        id[i] = lower_bound(values.begin(), values.end(), a[i]) - values.begin();
    }

    vector<ull> randomValue(m);
    for (int i = 0; i < m; i++) {
        randomValue[i] = splitmix64(i + 123456789ULL);
    }

    vector<ull> allHashes;
    allHashes.reserve(1LL * n * (n + 1) / 2);

    vector<int> seen(m, -1);

    for (int r = 0; r < n; r++) {
        ull currentHash = 0;

        for (int l = r; l >= 0; l--) {
            int x = id[l];

            if (seen[x] != r) {
                seen[x] = r;
                currentHash += randomValue[x];

                allHashes.push_back(currentHash);
            }
        }
    }

    sort(allHashes.begin(), allHashes.end());
    allHashes.erase(unique(allHashes.begin(), allHashes.end()), allHashes.end());

    cout << allHashes.size() << '\n';

    return 0;
}