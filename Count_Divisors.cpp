#include <bits/stdc++.h>
#define o() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    o();
    int l, r, k;
    cin >> l >> r >> k;
    cout << (r / k) - ((l - 1) / k) << endl;
    return 0;
}