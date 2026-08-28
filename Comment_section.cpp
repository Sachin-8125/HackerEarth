#include<bits/stdc++.h>
using namespace std;

int solution(int N, string S, vector<string> comments) {
    int count = 0;
    transform(S.begin(), S.end(), S.begin(), ::tolower);
    
    for (string comment : comments) {
        transform(comment.begin(), comment.end(), comment.begin(), ::tolower);
        stringstream ss(comment);
        string word;
        while (getline(ss, word, '_')) {
            if (word == S) {
                count++;
                break;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    if (!(cin >> N)) return 0;
    
    string S;
    cin >> S;
    
    vector<string> comments(N);
    for(int i = 0; i < N; i++) {
        cin >> comments[i];
    }
    
    cout << solution(N, S, comments) << "\n";
    
    return 0;
}