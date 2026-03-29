//dp

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

string memo_lower[20][2];
bool vis_lower[20][2];

string memo_upper[20][2];
bool vis_upper[20][2];

// DP to find the LARGEST lucky number <= S
string solve_lower(int idx, bool tight, const string& S) {
    if (idx == S.length()) return "";
    if (vis_lower[idx][tight]) return memo_lower[idx][tight];
    
    int limit = tight ? (S[idx] - '0') : 9;
    
    // We want the largest possible, so we iterate downwards
    for (int d = limit; d >= 1; --d) {
        if (d % 2 != 0) { // Must be odd
            bool new_tight = tight && (d == limit);
            string res = solve_lower(idx + 1, new_tight, S);
            
            // If the rest of the string could be formed validly
            if (res != "-1") {
                vis_lower[idx][tight] = true;
                return memo_lower[idx][tight] = to_string(d) + res;
            }
        }
    }
    
    vis_lower[idx][tight] = true;
    return memo_lower[idx][tight] = "-1"; // Invalid path
}

// DP to find the SMALLEST lucky number >= S
string solve_upper(int idx, bool tight, const string& S) {
    if (idx == S.length()) return "";
    if (vis_upper[idx][tight]) return memo_upper[idx][tight];
    
    int start = tight ? (S[idx] - '0') : 1;
    
    // We want the smallest possible, so we iterate upwards
    for (int d = start; d <= 9; ++d) {
        if (d % 2 != 0) { // Must be odd
            bool new_tight = tight && (d == start);
            string res = solve_upper(idx + 1, new_tight, S);
            
            // If the rest of the string could be formed validly
            if (res != "-1") {
                vis_upper[idx][tight] = true;
                return memo_upper[idx][tight] = to_string(d) + res;
            }
        }
    }
    
    vis_upper[idx][tight] = true;
    return memo_upper[idx][tight] = "-1"; // Invalid path
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    if (cin >> S) {
        unsigned long long N = stoull(S);
        int K = S.length();
        
        memset(vis_lower, false, sizeof(vis_lower));
        memset(vis_upper, false, sizeof(vis_upper));
        
        // 1. Get the Lower Bound Candidate
        string lower_str = solve_lower(0, true, S);
        if (lower_str == "-1" || lower_str == "") {
            // If no valid number of the same length exists, it must be (K-1) digits of '9's
            if (K > 1) lower_str = string(K - 1, '9');
            else lower_str = "0"; // Failsafe, though constraints say N >= 1
        }
        
        // 2. Get the Upper Bound Candidate
        string upper_str = solve_upper(0, true, S);
        if (upper_str == "-1") {
            // If no valid number of the same length exists, it must be (K+1) digits of '1's
            upper_str = string(K + 1, '1');
        }
        
        // 3. Compare distances
        unsigned long long L = stoull(lower_str);
        unsigned long long U = stoull(upper_str);
        
        unsigned long long diff_L = N - L; 
        unsigned long long diff_U = U - N;
        
        // Output the closest. Tie-breaker goes to the smaller number (L)
        if (diff_L <= diff_U) {
            cout << L << "\n";
        } else {
            cout << U << "\n";
        }
    }
    
    return 0;
}


// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// int main() {
//     // Fast I/O
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     string S;
//     if (cin >> S) {
//         unsigned long long N = stoull(S);
//         vector<string> candidates;
        
//         int K = S.length();
        
//         // Candidate 1: Number with (K-1) digits (Maximum possible: all 9s)
//         if (K > 1) {
//             candidates.push_back(string(K - 1, '9'));
//         }
        
//         // Candidate 2: Number with (K+1) digits (Minimum possible: all 1s)
//         candidates.push_back(string(K + 1, '1'));
        
//         // Candidate 3: Numbers with exactly K digits
//         string prefix = "";
//         bool all_odd = true;
        
//         for (int i = 0; i < K; ++i) {
//             int D = S[i] - '0';
            
//             // Branch 1: Try smaller odd digit at position i
//             int smaller_odd = -1;
//             for (int d = D - 1; d >= 1; --d) {
//                 if (d % 2 != 0) {
//                     smaller_odd = d;
//                     break;
//                 }
//             }
//             if (smaller_odd != -1) {
//                 candidates.push_back(prefix + to_string(smaller_odd) + string(K - 1 - i, '9'));
//             }
            
//             // Branch 2: Try greater odd digit at position i
//             int greater_odd = -1;
//             for (int d = D + 1; d <= 9; ++d) {
//                 if (d % 2 != 0) {
//                     greater_odd = d;
//                     break;
//                 }
//             }
//             if (greater_odd != -1) {
//                 candidates.push_back(prefix + to_string(greater_odd) + string(K - 1 - i, '1'));
//             }
            
//             // If the current digit is even, we cannot maintain the exact prefix anymore
//             if (D % 2 == 0) {
//                 all_odd = false;
//                 break;
//             }
//             // Append the odd digit to the prefix to continue checking matches
//             prefix += S[i];
//         }
        
//         // If N itself only has odd digits, it is a perfectly valid candidate (Distance = 0)
//         if (all_odd) {
//             candidates.push_back(S);
//         }
        
//         unsigned long long min_diff = -1; // -1 on unsigned rolls over to the Maximum Possible Value
//         unsigned long long best_ans = -1;
        
//         // Evaluate all possible candidates
//         for (const string& cand : candidates) {
//             unsigned long long X = stoull(cand);
//             unsigned long long diff = (X > N) ? (X - N) : (N - X);
            
//             // Select the one with the smallest difference
//             if (diff < min_diff) {
//                 min_diff = diff;
//                 best_ans = X;
//             } 
//             // Resolve ties by picking the smaller lucky number
//             else if (diff == min_diff) {
//                 if (X < best_ans) {
//                     best_ans = X;
//                 }
//             }
//         }
        
//         cout << best_ans << "\n";
//     }
    
//     return 0;
// }

