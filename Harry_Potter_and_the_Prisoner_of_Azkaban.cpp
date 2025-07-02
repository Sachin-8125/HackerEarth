#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    while(q--){
        int m;
        cin>>m;
        int k = __gcd(arr[0],m);
        for(int i=1;i<n;i++){
            k = max(k,__gcd(m,arr[i]));
        }
        cout<<k<<endl;
    }
}