#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; 
    cin>>s;
    vector<ll>dp(3,0);
    for(int i = 0; i<s.size(); i++){
        if(s[i]=='a'){
            dp[0] = (2*dp[0]+1)%mod;
        }
        else if(s[i]=='b'){
            dp[1] = (dp[1]*2+dp[0])%mod;
        }
        else if(s[i]=='c'){
            dp[2] = (dp[2]*2+dp[1])%mod;

        }
    }
    cout<<dp[2]<<endl;
    return 0;
}