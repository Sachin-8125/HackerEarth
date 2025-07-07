#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    stack<int> s1;
    stack<int> s2;
    for(int i=0; i<n; i++){
        s1.push(arr[i]);
    }
    for(int i=n-1; i>=0; i--){
        s2.push(arr[i]);
    }
    while(!s1.empty() && !s2.empty()){
        if(s1.top() > s2.top()){
            cout<<2<<' ';
            s2.pop();
        }
        else if(s1.top() < s2.top()){
            cout<<1<<' ';
            s1.pop();
        }
        else if(s1.top() == s2.top()){
            cout<<0<<' ';
            s1.pop(); s2.pop();
        }
    }
    return 0;
}