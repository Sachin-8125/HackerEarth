#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    set<int> bag;

    for (int i = 0; i < N; ++i) {
        int X;
        cin >> X;

        auto it = bag.lower_bound(X);

        int smaller = -1;
        int greater = -1;

        if (it != bag.begin()) {
            smaller = *prev(it);
        }

        if (it != bag.end()) {
            greater = *it;
        }

        cout << smaller << " " << greater << "\n";

        bag.insert(X);
    }

    return 0;
}