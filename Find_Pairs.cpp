#include <bits/stdc++.h>
using namespace std;

// Finds the lowest index in 'arr' such that arr[idx] + prevVal > mn
int binary_search_min(const vector<long long>& arr, long long prevVal, long long mn) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int md = l + (r - l) / 2;
        if (arr[md] + prevVal > mn)
            r = md - 1;
        else
            l = md + 1;
    }
    return l;
}

// Finds the highest index in 'arr' such that arr[idx] + prevVal <= mx
int binary_search_max(const vector<long long>& arr, long long prevVal, long long mx) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int md = l + (r - l) / 2;
        if (arr[md] + prevVal > mx)
            r = md - 1;
        else
            l = md + 1;
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    long long l, r;
    cin >> l >> r;

    vector<long long> v(n), odds, evens;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] % 2)
            odds.push_back(v[i]);
        else
            evens.push_back(v[i]);
    }

    sort(odds.begin(), odds.end());
    sort(evens.begin(), evens.end());

    int count = 0;
    for (int i = 0; i < odds.size(); ++i) {
        int right = binary_search_max(evens, odds[i], r);
        int left = binary_search_min(evens, odds[i], l);

        if (right < left || right < 0 || left >= evens.size())
            continue;
        count += (right - left + 1);
    }
    cout << count << endl;
    return 0;
}
