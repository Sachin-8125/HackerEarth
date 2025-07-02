#include<iostream>
using namespace std;
int main(){
    while(true){
        int x;
        cin>>x;
        if(x==42){
            exit(0);
        }
        cout<<x<<endl;
    }
}