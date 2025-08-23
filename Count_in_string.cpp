#include<bits/stdc++.h>
using namespace std;

int solve (string S, char k) {
   int count = 0;
   for(char ch : S){
    if(ch==k) count++;
   }
   return count;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        string S;
        cin >> S;
        char k;
        cin >> k;

        int out_;
        out_ = solve(S, k);
        cout << out_;
        cout << "\n";
    }
}