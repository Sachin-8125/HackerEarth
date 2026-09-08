#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        
        int k = 1;
        long long groupSize = 4; 
        while (n > groupSize) {
            n -= groupSize;
            k++;
            groupSize *= 4;
        }
        
        n--; 
        
        string half(k, 'a');
        for (int i = k - 1; i >= 0; i--) {
            half[i] = 'a' + (n % 4);
            n /= 4;
        }
        
        string result = half;
        for (int i = k - 1; i >= 0; i--) {
            result += half[i];
        }
        
        cout << result << endl;
    }
    
    return 0;
}