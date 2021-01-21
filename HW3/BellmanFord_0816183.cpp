#include <cmath>
#include<cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct edge edge;
struct edge{
	int from;
	int to;
	int distance;
};
int main() {
	int nodes,edges,start,end,a,b,c;
	cin>>nodes>>edges;
	cin>>start>>end;
	edge poi[edges];
	int key[nodes];
	for(int i=0;i<nodes;i++){
		key[i]=100000;
	}
	key[start]=0;
	for(int i=0;i<edges;i++){
		cin>>a>>b>>c;
		poi[i]={.from=a,.to=b,.distance=c};
	}
	for(int i=0;i<edges;i++){
		for(int j=0;j<edges;j++){
			int tmp=key[poi[j].from]+poi[j].distance;
			if(tmp<key[poi[j].to]){
				key[poi[j].to]=tmp;
			}
		}
	}
	int check[nodes];
	for(int i=0;i<nodes;i++){
		check[i]=key[i];
	}
	int negative=0;
	for(int i=0;i<edges;i++){
		int tmp=check[poi[i].from]+poi[i].distance;
		if(tmp<check[poi[i].to]){
			  check[poi[i].to]=tmp;
			}
		}		
	for(int i=0;i<nodes;i++){
		if(check[i]!=key[i]){
			negative++;
		}
	}
	if(negative>0){
		cout<<"Negative loop detected!\n";
	}else{
		cout<<key[end]<<"\n";
	}
	
    return 0;
}

