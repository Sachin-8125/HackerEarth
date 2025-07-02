#include <iostream>
using namespace std;

string winner(int N, int X) {
    string str = "Jojo";  
    while (N > 1) {
        N -= 2;
        str = (str == "Mojo") ? "Jojo" : "Mojo";
    }
    if (N == 0) return str;
    while (X > 0) {
        X = (X % 2 == 0) ? X / 2 : (X + 1) / 2;
        str = (str == "Mojo") ? "Jojo" : "Mojo";
    }
    return str;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int N, X;
        cin >> N >> X;
        cout << winner(N, X) << '\n';
    }

    return 0;
}
