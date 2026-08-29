#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    int mod = 1000000007;
    
    vector<int> arr(1002);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 2;
    for (int i = 4; i < 1002; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % mod;
    }

    vector<vector<long long>> fib(1000001, vector<long long>(2));
    fib[0][0] = arr[999];
    fib[0][1] = arr[1000];
    
    for (int i = 1; i < 1000001; i++) {
        fib[i][0] = (arr[1000] * fib[i - 1][1] + arr[999] * fib[i - 1][0]) % mod;
        fib[i][1] = (arr[1001] * fib[i - 1][1] + arr[1000] * fib[i - 1][0]) % mod;
    }

    for (int i = 0; i < T; i++) {
        string x;
        long long m;
        cin >> x >> m;

        long long n = 0;
        for (size_t j = 0; j < x.length(); j++) {
            n = (n * 10 + (x[j] - '0')) % m;
        }

        long long t = std::gcd(m, n);

        if (t > 1001) {
            int a = t / 1000;
            int b = t % 1000;
            long long val = (arr[b + 1] * fib[a - 1][1] + arr[b] * fib[a - 1][0]) % mod;
            cout << val << "\n";
        } else {
            cout << arr[t] << "\n";
        }
    }

    return 0;
}