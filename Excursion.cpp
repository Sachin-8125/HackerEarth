#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int boys = ceil((double)n/k);
        int girls = ceil((double)m/k);
        cout<<boys+girls<<endl;
    }
    return 0;
}