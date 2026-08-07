#include<iostream>
#include<vector> 
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if(!(cin >> n)) return 0;

    string s;
    cin >> s;

    vector<vector<int>> pref(26, vector<int>(n + 1, 0));

    for(int i = 0; i < n; i++){
        for(int c = 0; c < 26; c++){
            pref[c][i + 1] = pref[c][i];
        }
        pref[s[i] - 'a'][i + 1]++;
    }

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        
        int distinct_count = 0;
        for(int c = 0; c < 26; c++){
            if(pref[c][r] - pref[c][l - 1] > 0){
                distinct_count++;
            }
        }
        cout << distinct_count << "\n";
    }
    
    return 0;
}