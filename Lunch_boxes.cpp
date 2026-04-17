#include <iostream>
#include <algorithm>
using namespace std;

int lunchReceive(int m, int arr[], int k) {
    int sum = 0, count = 0;
    
    for (int i = 0; i < k; i++) {
        sum += arr[i];
        if (sum <= m) {
            count++;
        } else {
            break;
        }
    }
    
    return count;
}

int main() {
    int a, b, c;
    cin >> a;
    
    while (a--) {
        cin >> b >> c;
        
        int arr[c];
        for (int i = 0; i < c; i++) {
            cin >> arr[i];
        }
        
        sort(arr, arr + c);
        cout << lunchReceive(b, arr, c) << "\n";
    }
    
    return 0;
}