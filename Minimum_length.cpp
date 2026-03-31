#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int num;
    cin >> num;  
    int n,x,r,l;
    for(int i=0;i<num;i++){
        vector<int>arr1,arr2;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>x;
            arr1.push_back(x);
        }
        for(int j=0;j<n;j++){
            cin>>x;
            arr2.push_back(x);
        }
        l=0,r=n-1;
        while(arr1[l]==arr2[l])l++;
        while(arr1[r]==arr2[r])r--;
        if(r>l)cout<<r-l+1<<endl;
        else cout<<0<<endl;
    }
}