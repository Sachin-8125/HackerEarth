#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while(T--){
        int K;
        cin >> K;
        string S;
        cin >> S;
        int n = S.size();
        long long countValid = 0;
        for (int i = 0; i < n; i++){
            int num = S[i] - '0';
            if(num % 8 == 0 && num % 3 != 0) {
                countValid++;
            }
        }
        for (int i = 0; i < n - 1; i++){
            int num = (S[i]-'0') * 10 + (S[i+1]-'0');
            if(num % 8 == 0 && num % 3 != 0){
                countValid++;
            }
        }
        vector<int> prefix(n + 1, 0);
        prefix[0] = 0;
        for (int i = 0; i < n; i++){
            prefix[i+1] = (prefix[i] + (S[i]-'0')) % 3;
        }
        int freq[3] = {0, 0, 0}; 
        freq[prefix[0]] = 1;
        int nextIdx = 1; 
        
        for (int j = 2; j < n; j++){
            while(nextIdx <= j - 2) {
                freq[prefix[nextIdx]]++;
                nextIdx++;
            }
            int lastThree = (S[j-2]-'0') * 100 + (S[j-1]-'0') * 10 + (S[j]-'0');
            if(lastThree % 8 == 0){
                int p = prefix[j+1];
                countValid += ((j - 1) - freq[p]);
            }
        }
        
        cout << countValid << "\n";
    }
    
    return 0;
}