#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n=0;
    long long temp = 1000000007;
    cin>>n;
    long long int arr[n];
    for(long long int i=0; i<n; i++){
        cin>>arr[i];
    }
    long long int gc = arr[0];
    for(long long int i=1; i<n; i++){
        gc = __gcd(gc, arr[i]);
    } 
    long long int pr = 1, z=1;
    for(long long i=0; i<n; i++){
        pr = pr*arr[i];
        pr = pr%temp;
    }
    pr = pr%temp;
    for(long long i=0; i<gc; i++){
        z = z*pr;
        z = z%temp;
    }
    z = z%temp;
    cout<<z<<"\n";
}