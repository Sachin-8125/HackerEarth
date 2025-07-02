
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main() {
	int n;
	cin >> n;   
      vector<long long>arr(n);
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
    int j=0;
	unordered_map<int,int>mp;
	for (int i=0;i<n;i++){
        mp[arr[i]]++;
	  while  (mp.find(j)!=mp.end()){
                     j++;
		}
		arr[i]=j;
	}
	for (int i:arr){
		cout<<i<<" ";
	}


}