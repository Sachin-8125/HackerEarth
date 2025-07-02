#include <bits/stdc++.h> 
using namespace std; 
int main(){     
    string s; 
    cin >>s;     
    int a=0,b=0,c=0,d=0;   
    if(s[2]=='A'||s[2]=='E'||s[2]=='I'||s[2]=='O'||s[2] =='U'||s[2]=='Y'){          
        cout <<"invalid"<<"\n";          
        return 0;     
    }     
    a = s[0] - '0' + s[1] - '0';     
    b = s[3] - '0' + s[4] - '0';     
    c = s[4] - '0' + s[5] - '0';     
    d = s[7] - '0' + s[8] - '0';     
    if(a%2==0 and b % 2==0 and c % 2==0 and d%2==0){          
        cout <<"valid"<<"\n";     
    }else{         
        cout <<"invalid"<<"\n";     
    }     
    return 0;
}