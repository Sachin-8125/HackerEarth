#include<iostream>
using namespace std;
int main(){
    string str;
    cin>>str;
    int x=0,y=0;
    for(int i=0;i<str.size();i++){
        str[i]=='z' ? x++ : y++;
    }
    cout<< (2*x==y?"Yes":"No")<<endl;
}