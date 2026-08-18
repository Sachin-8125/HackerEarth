#include <bits/stdc++.h>
using namespace std;

string encode(const string& s) {
    string t = s;
    for (char& c : t) {
        c = 'z' - (c - 'a');
    }
    return t;
}

long long findMessages(int N, vector<string>& A) {
    unordered_set<string> S(A.begin(), A.end());
    long long answer = 0;
    unordered_set<string> visited;
    
    for (const string& s : A) {
        if (visited.count(s)) continue;
        string e = encode(s);
        
        if (e == s) {
            answer += 1;
            visited.insert(s);
        } else if (S.count(e)) {
            answer += 1;
            visited.insert(s);
            visited.insert(e);
        } else {
            answer += 1;
            visited.insert(s);
        }
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    cout << findMessages(N, A) << "\n";
    
    return 0;
}