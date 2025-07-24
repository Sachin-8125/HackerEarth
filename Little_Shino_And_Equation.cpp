#include<iostream>
using namespace std;
int main(){
    int a,b,d;
    cin>>a>>b>>d;
    int jumps=0;
    if(a>b) swap(a,b);
    jumps += d/b;
    d -= jumps*b;
    jumps += d;
    cout<<jumps<<endl;
}