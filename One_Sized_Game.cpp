#include <iostream>
#include <vector>
using namespace std;

string playGame(vector<int>& arr) {
    while (arr.size() > 1) {
        // Find the minimum value and its index (smallest index if duplicate)
        int minIndex = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }
        int subtractVal = minIndex + 1; // Since array is 1-indexed
        // Subtract and remove elements < 0 in one pass
        int write = 0;
        for (int read = 0; read < arr.size(); ++read) {
            arr[read] -= subtractVal;
            if (arr[read] >= 0) {
                arr[write++] = arr[read]; // keep valid values
            }
        }
        arr.resize(write); // remove elements that went below 0
    }

    return (arr.size() == 1) ? "Ladia" : "Kushagra";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }
        cout << playGame(arr) << endl;
    }
    return 0;
}

