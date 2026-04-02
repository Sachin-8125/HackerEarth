#include<bits/stdc++.h>
using namespace std;
vector<long long> MinMax (int A, int B) {
    long long max_houses = A - B + 1;
    long long max_connections = (max_houses * (max_houses - 1)) / 2;

    long long q = A / B;
    long long r = A % B;
    
    long long min_connections = r * (q + 1) * q / 2 + (B - r) * q * (q - 1) / 2;

    return {min_connections, max_connections};
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int A;
    cin >> A;
    int B;
    cin >> B;

    vector<long long> out_;
    out_ = MinMax(A, B);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}