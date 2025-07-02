#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

// The Simple Function as described
int SimpleFunction(const string& A, const string& B) {
    int answer = 0;
    for (int dig = 1; dig <= 9; dig++) {
        char ch = dig + '0';
        if (A.find(ch) != string::npos && B.find(ch) != string::npos) {
            answer = answer * 10 + dig;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;

    while (T--) {
        int N1, N2;
        cin >> N1 >> N2;

        vector<string> basket1(N1), basket2(N2);

        for (int i = 0; i < N1; i++) {
            cin >> basket1[i];
        }

        for (int i = 0; i < N2; i++) {
            cin >> basket2[i];
        }

        int total_pairs = N1 * N2;
        int even_count = 0;

        // Check every pair from basket1 and basket2
        for (int i = 0; i < N1; i++) {
            for (int j = 0; j < N2; j++) {
                int value = SimpleFunction(basket1[i], basket2[j]);
                if (value % 2 == 0) {
                    even_count++;
                }
            }
        }

        // Calculate and print probability up to 3 decimal places
        double probability = (double)even_count / total_pairs;
        cout << fixed << setprecision(3) << probability << endl;
    }

    return 0;
}
