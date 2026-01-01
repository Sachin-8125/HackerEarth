#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    assert(n>=1 && n<=100);
    int q;
    cin>>q;
    assert(q>=1 && q<=1e4);
    int cur[105]={0};
    while(q--){
        int x;
        cin>>x;
        assert(x>=1 && x<=1e5);
        int val=min(x,n);
        bool f=0;
        for(int i=val;i>=1;i--){
            if(cur[i]<x){
                cur[i]=x;
                cout<<"YES\n";
                f=1;
                break;
            }
        }
        if(!f)cout<<"NO\n";
    }
    return 0;
}