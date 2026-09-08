#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int x;

    stack<int> st;
    vector<int> ans;

    for(int i=0; i<n; i++){
        cin>> x;
        if(!st.empty() && x==0){
            int x = st.top();
            st.pop();
            ans.push_back(x);
        }
        else st.push(x);
    }
    
    int res = 0;

    for(int num : ans){
        cout<<num<<" ";
    }
     
    return 0;
}