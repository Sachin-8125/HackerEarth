#include <iostream>
#include <algorithm>

using namespace std;

long long countSetBits(long long n, int x) {
    if (n <= 0) return 0;
    
    int k = x - 1;
    long long cycle_len = 1LL << (k + 1);
    long long half_cycle = 1LL << k;
    
    long long total_numbers = n + 1;
    long long full_cycles = total_numbers / cycle_len;
    long long rem = total_numbers % cycle_len;
    
    return (full_cycles * half_cycle) + max(0LL, rem - half_cycle);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    if (cin >> q) {
        while (q--) {
            long long l, r;
            int x;
            cin >> l >> r >> x;
            
            cout << countSetBits(r, x) - countSetBits(l - 1, x) << "\n";
        }
    }
    
    return 0;
}