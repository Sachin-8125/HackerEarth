#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
ll fastmod(ll a,ll b,ll m){
    ll ans=1;
    a=a%m;
    if(a==0) return 0;
    while(b>0){
        if(b&1)
        ans=(ans*a)%m;
        b=b>>1;
        a=(a*a)%m;
    }
    return ans;
}   

ll inv(ll a,ll m){
    return fastmod(a,m-2,m);
}
int main(){
    fast;
    ll t,n,a;
    cin>>t;
    ll m= 1000000007;
    while(t--){
        cin>>n;
        cout<<((n)%m*(n-1)%m*(n-1)%m*inv(4,m)%m)%m<<" "<<((n)%m*(n-1)%m*(2*n-1)%m*inv(6,m))%m<<endl;
    }
}