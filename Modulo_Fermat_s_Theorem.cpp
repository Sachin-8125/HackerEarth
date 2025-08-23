#include <iostream>
using namespace std;

// Function to check if there exists x such that x^2 ≡ a (mod p)
bool hasSolution(int a, int p) {
    if (a == 0) return true; // Trivially, x=0 works
    // Euler's Criterion: a^((p-1)/2) ≡ 1 mod p ⇔ quadratic residue
    int res = 1, exp = (p - 1) / 2;
    int base = a % p;
    while (exp) {
        if (exp % 2) res = (1LL * res * base) % p;
        base = (1LL * base * base) % p;
        exp /= 2;
    }
    return res == 1;
}

int main() {
    int p, n;
    cin >> p >> n;
    int count = 0;
    for (int a = 1; a <= n; a++) {
        if (hasSolution(a, p)) count++;
    }
    cout << count << endl;
    return 0;
}
