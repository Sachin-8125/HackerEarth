#include<iostream>
#include<vector>
using namespace std;
const int MOD = 1e9+7;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long prod = 1;
    for(int i=0;i<n;i++){
        prod = (prod*v[i])%MOD;
    }
    cout<<prod;
}