#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int a = *min_element(arr,arr+n);
    int b = *max_element(arr,arr+n);
    int flag = 0;
    for(int i=a;i<b;i++){
        for(int j=0;j<n;j++){
            if(arr[j]==i){
                flag++;
                break;
            }
        }
    }
    cout<<(flag==b-a?"YES":"NO")<<endl;
}