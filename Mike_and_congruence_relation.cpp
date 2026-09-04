#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    if (cin >> n >> k) {
        long long base_count = n / k;
        long long extra_rem = n % k;

        long long total_pairs = 0;

        if (extra_rem > 0) {
            long long count_with_extra = base_count + 1;
            long long pairs_per_rem = (count_with_extra * (count_with_extra - 1)) / 2;
            total_pairs += extra_rem * pairs_per_rem;
        }

        if (base_count > 0) {
            long long pairs_per_rem = (base_count * (base_count - 1)) / 2;
            total_pairs += (k - extra_rem) * pairs_per_rem;
        }

        cout << total_pairs << "\n";
    }

    return 0;
}