#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void swap(int *a, int *b){
	int *temp;
	*temp=*a;
	*a=*b;
	*b=*temp;
}

int main() {
    int times,len,total,length,middle;
    cin >> times;
    while(times--){
    	total=0;
    	cin>>len;
    	int arr[len]={0};
    	for(int i=0;i<len;i++){
    		cin>>arr[i];
		}
		for(int j=0;j<len-1;j++){
			for(int k=0;k<len-j-1;k++){
				if(arr[k]>arr[k+1]){
					swap(&arr[k],&arr[k+1]);
				}
			}
		}
		middle=arr[len/2];
		for(int i=0;i<len;i++){
			length=middle-arr[i];
			if(length<0){
				total-=length;
			}else {
				total+=length;
			}
		}
		cout<<total;
	}
    return 0;
}

