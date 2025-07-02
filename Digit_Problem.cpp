#include<iostream>
#include<string>
using namespace std;

int main(){
    string a;
    cin>>a;
    int c;
    cin>>c;
    int d=c;
    for(int i=0;i<a.length();i++){
        if(a[i]!='9' && c>0){
            a[i]='9';
            c--;
        }
    }
    cout<<a;
}