#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void showTokenFrequency(string input){
	for(int i=0;i<input.size();i++){
		if(input[i]==',' || input[i]=='.'){
			input.erase(i,1);
		}
		if(input[i]>=65 && input[i]<=90){
			input[i]+=32;
		}
	}
	stringstream ss;
    ss << input;
	string div_list[50];
	string save_list[50];
	string div;
	int i=0;
	int count[50]={0};
	while(getline(ss,div,' ')){
		div_list[i]=div;
		save_list[i]=div;
		count[i]++;
	for(int j=0;j<50;j++){
			if(save_list[j]==div_list[i] && i !=j){
				count[j]++;
				count[i]--;
				break;
			}
		}
		i++;
	}
	for(int k=0;k<50;k++){
		if(count[k]!=0){
		cout << div_list[k]<<" "<<count[k]<<endl;			
		}
		
	}
}

int main(){
    string input;
    int count = 0;
    while(getline(cin, input)){
        cout<<"case "<< ++count <<endl;
        showTokenFrequency(input);
    }
    return 0;
}
