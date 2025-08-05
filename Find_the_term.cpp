#include <iostream>
using namespace std;
const int mod = 1e9+7;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        long long m;
        cin>>m;
        long long i=3;
        while(i<=m){
            long long c=(a-b)%mod;
            a=b;
            b=c;
            i++;
        }
        cout<<b<<endl;
    }
    return 0;
}