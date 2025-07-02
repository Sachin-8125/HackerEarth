#include<iostream>
#include<string>
using namespace std;

bool check(string s1, string s2){
    int n=s1.size(),m=s2.size();
    string ans="";
    int i=0,j=0;
    while(i<n and j<m){
        if(s2[j]==s1[i]){
            ans += s1[i];
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    return ans==s2;

}
string reverse(string x){
    int i=0,j=x.size()-1;
    while(i<j){
        swap(x[i++],x[j--]);
    }
    return x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    while(n--){
        string parStr,childStr;
        cin>>parStr>>childStr;
        string temp = reverse(childStr);
        if(check(parStr,childStr) and check(parStr,temp)) cout<<"GOOD STRING"<<endl;
        else cout<<"BAD STRING"<<endl;
        
    }
}