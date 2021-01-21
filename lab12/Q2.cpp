#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){

    while(1){
    	int n;
		int result=0;    	
    	cin>>n;
	
    	if(n==0){
    		break;
		}
        vector<int> arr;		
		for(int i=0;i<n;i++){
			int tmp;
			cin>>tmp;
			arr.push_back(tmp);
		}
		sort(arr.begin(),arr.end(),greater<int>());
		for(int i=n-1;i>0;i--){
			int tmp=arr[i]+arr[i-1];
			result +=tmp;
			arr.pop_back();
			arr.pop_back();
			arr.push_back(tmp);
			sort(arr.begin(),arr.end(),greater<int>());
		}
		cout<<result<<"\n";
	}
    return 0;
}
    


