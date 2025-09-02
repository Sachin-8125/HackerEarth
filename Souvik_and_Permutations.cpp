#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// Function to calculate (base^exp) % MOD
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to calculate modular inverse using Fermat's little theorem
long long modInverse(long long a, long long mod) {
    return power(a, mod - 2, mod);
}

// Function to calculate factorial % MOD
long long factorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

// Function to calculate permutations with repetition: n! / (n1! * n2! * ... * nk!)
long long permutationsWithRepetition(int total, map<char, int>& freq) {
    if (total == 0) return 1;
    
    long long numerator = factorial(total);
    long long denominator = 1;
    
    for (auto& pair : freq) {
        denominator = (denominator * factorial(pair.second)) % MOD;
    }
    
    return (numerator * modInverse(denominator, MOD)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        string vowels = "aeiou";
        map<char, int> vowelFreq, consonantFreq;
        int vowelCount = 0, consonantCount = 0;
        
        // Count vowels and consonants
        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                vowelFreq[c]++;
                vowelCount++;
            } else {
                consonantFreq[c]++;
                consonantCount++;
            }
        }
        
        // Calculate permutations for vowels and consonants separately
        long long vowelPerms = permutationsWithRepetition(vowelCount, vowelFreq);
        long long consonantPerms = permutationsWithRepetition(consonantCount, consonantFreq);
        
        // Total permutations = vowel_permutations * consonant_permutations
        long long result = (vowelPerms * consonantPerms) % MOD;
        
        cout << result << "\n";
    }
    
    return 0;
}