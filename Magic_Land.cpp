#include <bits/stdc++.h> 
using namespace std; 
int arr[1009][1009]; 
int row[1009][1009]; 
int col[1009][1009]; 
int main() {    
    int t;    
    cin >> t;    
    while(t--){        
        int n, m;        
        cin >> n>>m;        
        for(int i = 1; i <= n; ++i)            
            for(int j = 1; j <= m; ++j)                
                cin>>arr[i][j];        
        int colMax = 0, rowMax = 0;        
        for(int i = 1; i <= n; i++){            
            for(int j = 1; j <= m; j++){                         
                col[i][j]=1;                
                if (i >1 && arr[i][j] == arr[i - 1][j]) col[i][j] += col[i - 1][j];                           
                row[i][j] = 1;                
                if (j > 1 && arr[i][j] == arr[i][ j -1]) row[i][j] += row[i][j - 1];                
                colMax = col[i][j] > colMax ? col[i][j] : colMax;                
                rowMax = row[i][j] > rowMax ? row[i][j] : rowMax;            
            }            
        }        
        cout<<colMax*rowMax<<endl;    
    }    
    return 0; 
}