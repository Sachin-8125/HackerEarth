#include<iostream>
#include<vector>
using namespace std;
int main(){
    string str;
    cin>>str;
    int i=0,j=str.size()-1;
    while(i<j){
        if(str[i]!=str[j]){
            cout<<"NO";
            exit(0);
        }
        i++;
        j--;
    }
    cout<<"YES";
}