#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;cin>>n>>q;
    long long int A[n],B[n];
    for(int i = 0; i<n; i++){
        cin>>A[i];
        while(A[i]>9){
            long long int sum = 0;
            while(A[i]>0){
                long long int rem = A[i]%10;
                sum+=rem;
                A[i] = A[i]/10;
            }
            A[i] = sum;
        }
        B[i] = A[i];
    }
    sort(A,A+n);
    sort(B,B+n,greater<long long int>());
    for(int i = 0; i<n; i++){
        A[i+1]+=A[i];
        B[i+1]+=B[i];
    }
    sort(A,A+n);
    while(q--){
        int x,k;cin>>x>>k;
        if(x==1){
            cout<<B[k-1]<<endl;;
        }
        if(x==2){
            cout<<A[k-1]<<endl;;
        }
    }
    return 0;
}