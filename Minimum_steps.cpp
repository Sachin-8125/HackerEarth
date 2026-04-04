#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

// function for lis - O(n log n) to find length of longest increasing subsequence
ll lis(const vector<ll>& a) {
    vector<ll> v;
    v.push_back(a[0]);

    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i] > v.back()) {
            v.push_back(a[i]);
        } else {
            auto index = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[index] = a[i];
        }
    }

    return v.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> a(n);
    for (auto& x : a) {
        cin >> x;
    }

    ll ans1 = n - lis(a);

    reverse(a.begin(), a.end());
    ll ans2 = n - lis(a);

    cout << min(ans1, ans2) << endl;

    return 0;
}