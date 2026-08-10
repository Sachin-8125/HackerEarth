#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    unordered_map<int, long long> freq;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    
    long long ans = 0;
    for (auto& pair : freq) {
        long long f = pair.second;
        ans += f * (f - 1) / 2;
    }
    
    cout << ans << endl;
    
    return 0;
}