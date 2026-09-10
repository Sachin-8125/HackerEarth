#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    priority_queue<long long> pq;
    for (int i = 0; i < m; ++i) {
        long long x;
        cin >> x;
        pq.push(x);
    }

    long long total = 0;

    while (n--) {
        long long top = pq.top();
        pq.pop();
        total += top;
        pq.push(top - 1);
    }

    cout << total << "\n";

    return 0;
}
