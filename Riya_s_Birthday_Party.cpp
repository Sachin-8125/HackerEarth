#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define endl "\n"
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans = (1 + ( ( (2*n + 1)%mod )*( (n-1)%mod ) )% mod )% mod;
        cout<<ans<<endl;
    }
    return 0;
}