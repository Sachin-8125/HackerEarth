#include<bits/stdc++.h>
using namespace std;

int Max (int N, int K, vector<int> arr) {
    vector<int> costs;
    int odd = 0, even = 0;

    for (int i = 0; i < N - 1; ++i) {
        arr[i]%2 ? odd++ : even++;
        if (odd==even) costs.push_back(abs(arr[i]-arr[i+1]));
    }

    sort(costs.begin(), costs.end());

    int cuts = 0;
    for (int cost : costs) {
        if (K >= cost) {
            K -= cost;
            cuts++;
        } else {
            break;
        }
    }

    return cuts;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<int> arr(N);
    for(int i_arr = 0; i_arr < N; i_arr++)
    {
    	cin >> arr[i_arr];
    }

    int out_;
    out_ = Max(N, K, arr);
    cout << out_;
}