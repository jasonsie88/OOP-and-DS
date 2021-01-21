#include<iostream>
#include<cstdio>
#include<vector>
#include<fstream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
	*a=*b;
	*b=temp; 	
}

int main(void){
	
	int i,temp,j,len;
	while(1){
		cin>>len;
		if(len==0){
			break;
		}
		int a[len];
		for(i=0;i<len;i++){
		   cin>>a[i];
	    }
	for(i=0;i<len-1;i++){
		for(j=0;j<len-i-1;j++){
			if(a[j]>a[j+1]){
			swap(&a[j],&a[j+1]);
			}
		}
	}
	for(i=0;i<len;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";

	}

	return 0;
}
