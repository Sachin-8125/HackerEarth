#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000000;
int pref[MAXN + 1];

bool isAlmightyPandigital(int n) {
    int mask = 0;
    int d = 0;
    int temp = n;
    
    while (temp > 0) {
        int digit = temp % 10;
        if (digit == 0) return false;
        if (mask & (1 << digit)) return false;
        mask |= (1 << digit);
        d++;
        temp /= 10;
    }
    
    for (int i = 1; i <= d; ++i) {
        if ((mask & (1 << i)) == 0) return false;
    }
    
    return true;
}

void precompute() {
    pref[0] = 0;
    for (int i = 1; i <= MAXN; ++i) {
        pref[i] = pref[i - 1] + (isAlmightyPandigital(i) ? 1 : 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int q;
    if (cin >> q) {
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << pref[r] - pref[l - 1] << "\n";
        }
    }
    
    return 0;
}