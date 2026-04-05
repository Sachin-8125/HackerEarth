#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> freq(2 * n + 1, 0);
    int offset = n;
    freq[offset] = 1; 
    
    long long curr_sum = 0;
    long long res = 0;
    
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        
        if (num % 2 != 0) {
            curr_sum += 1;
        } else {
            curr_sum -= 1;
        }
        
        res += freq[curr_sum + offset];
        freq[curr_sum + offset]++;
    }
    
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}