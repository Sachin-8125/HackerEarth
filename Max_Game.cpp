#include<bits/stdc++.h>
using namespace std;

int solve(int N) {
    int p = 1;
    while (p * 2 <= N) {
        p *= 2;
    }
    return p;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++) {
        int N;
        cin >> N;
        cout << solve(N) << "\n";
    }
    
    return 0;
}