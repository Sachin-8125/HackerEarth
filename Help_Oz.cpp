#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli i, m, j;
    cin >> m;
    lli a[m];
    for(i = 0; i < m; i++) {
        cin >> a[i];
    }
    vector<lli> divisors;
    sort(a, a + m);
    lli diff = a[1] - a[0];
    for(i = 1; i * i <= diff; i++) {
        if(diff % i == 0) {
            if(i * i == diff) {
                divisors.push_back(i);
            } else {
                divisors.push_back(i);
                divisors.push_back(diff / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    for(i = 0; i < divisors.size(); i++) {
        bool isValid = true;
        for(j = 2; j < m; j++) {
            if(a[j] % divisors[i] != a[1] % divisors[i]) {
                isValid = false;
                break;
            }
        }
        if(isValid && divisors[i] != 1) {
            cout << divisors[i] << " ";
        }
    }
    return 0;
}