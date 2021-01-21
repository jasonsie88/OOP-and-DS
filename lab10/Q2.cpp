#include <iostream>
using namespace std;


int main() {
    int times;
    cin>>times;
    while(times--){
    	int input,j,check;
    	int output=0;
    	int total;
    	cin>>input;
    	for(int i=1;i<input;i++){
    		total=0;
    		j=i;
    		check=0;
    
    		do{
				check+=(j%10);

				j/=10;
			}while(j!=0);

			total=i+check;

			if(total==input){
				output=i;
				break;
			}else{
				output=0;
			}
		}
		cout<<output<<endl;
	}
    return 0;
}
