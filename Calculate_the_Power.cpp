#include <iostream>
using namespace std;
long long moduloExponentiation(long long A, long long B, long long M) {
    long long result = 1;
    
    // Continue until exponent becomes 0
    while(B > 0) {
        // If B is odd, multiply result with A
        if(B % 2 == 1) {
            result = (result * A) % M;
        }
        
        // Square the base and halve the exponent
        A = (A * A) % M;
        B = B / 2;
    }
    
    return result;
}

int main() {
    // Constants
    const long long M = 1000000007;
    
    // Input variables
    long long A, B;
    cin >> A >> B;
    
    // Calculate result using modular exponentiation
    long long result = moduloExponentiation(A, B, M);
    
    // Output result
    cout << result;
    
    return 0;
}


