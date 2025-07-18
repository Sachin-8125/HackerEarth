#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ar[100001] = {0};
void permutationSum() {
    ar[0] = 0;
    ar[1] = 1;
    ar[2] = 1;
    for (ll i = 3; i < 100001; i++) {
        ar[i] = i - (i % 2) + ar[i - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    permutationSum();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << ar[n] << '\n';
    }
    return 0;
}