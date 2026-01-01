#include<iostream>
#include<cmath>
using namespace std;
const int MOD = 1e9+7;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long A,B,C,L,R;
        cin>>A>>B>>C>>L>>R;
        long long ans=0;
        for(long long i=L;i<=R;i++){
            ans += ((long long)pow(3,i)+(long long)pow(2,i)+1)%MOD;
        }
        cout<<ans<<endl;
    }
}
