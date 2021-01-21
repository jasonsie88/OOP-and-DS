#include <iostream>
#include <string>

using namespace std;

class BigInteger {
public:	
	BigInteger(){}
	
	
	BigInteger(string number){
		BigInteger::number1=number;		
		BigInteger::number=number;
	}
	string getnumber1()const{
		return BigInteger :: number1;
	}
	string getnumber() const{
		return BigInteger::number;
	}
   const BigInteger operator+(const BigInteger& k){
      string number2=k.number;
      if(number.size()<number2.size()){
    	string temp=number;
    	number=number2;
    	number2=temp;
     }
    	int length1=number.size(),flag=0,a,b,sum,length2=number2.size();
   		while(length1>0){
  		a=number[length1-1]-'0';
  		if(length2>0){
  			b=number2[length2-1]-'0';  			
		  }
  		else{
     		b=0;	  //陣列倒著加回去     0 1 2 3
			           //                  1 0 0 0		
		  }
  			sum=a+b+flag;
  		if(sum>=10){
   			number[length1-1]='0'+sum%10;
   			flag=1;
  		}else{
   			number[length1-1]='0'+sum;
   			flag=0;
  }
  			length1--;
  			length2--;
 }
 
 		if(flag==1)
  			number="1"+number;
 		return number;
}
	const BigInteger operator +=(const BigInteger&k){
	  number.erase();
      string number2=k.number;
      if(number.size()<k.number.size()){
    	string temp=number;
    	number=k.number;
    	number2=temp;
     }
    	int length1=number.size(),flag=0,a,b,sum,length2=number2.size();
   		while(length1>0){
  		a=number[length1-1]-'0';
  		if(length2>0)
   			b=number2[length2-1]-'0';
  		else
   			b=0;
  			sum=a+b+flag;
  		if(sum>=10){
   			number[length1-1]='0'+sum%10;
   			flag=1;
  }else{
   			number[length1-1]='0'+sum;
   			flag=0;
  }
  			length1--;
  			length2--;
 }
 
 		if(1==flag)
  		number="1"+number;
 		return number;
	}
	const BigInteger operator ++(int){
		string number2="1";
		BigInteger temp(number1);
       	int length1=number1.size(),flag=0,a,b,sum,length2=number2.size();
   		while(length1>0){
  			a=number1[length1-1]-'0';
  		if(length2>0)
   			b=number2[length2-1]-'0';
  		else
   			b=0;
  			sum=a+b+flag;
  		if(sum>=10){
   			number1[length1-1]='0'+sum%10;
   			flag=1;
  		}else{
   			number1[length1-1]='0'+sum;
   			flag=0;
  }
  			length1--;
  			length2--;
 }
 
 		if(1==flag)
  			number1="1"+number1;
		BigInteger::number=number1;
		return temp;
	}
	const BigInteger operator ++(){
			string number2="1";
       		int length1=number1.size(),flag=0,a,b,sum,length2=number2.size();
   			while(length1>0){
  				a=number1[length1-1]-'0';
  				if(length2>0)
   					b=number2[length2-1]-'0';
 				else
   					b=0;
  					sum=a+b+flag;
  				if(sum>=10){
   					number1[length1-1]='0'+sum%10;
   					flag=1;
  				}else{
   					number1[length1-1]='0'+sum;
   					flag=0;
  			}
  			length1--;
  			length2--;
 }
 
 		if(1==flag)
  			number1="1"+number1;
  		return number1;
	}
	private:
		string number;	
		string number1;	
};

	ostream& operator<<(ostream& out,const BigInteger& k){
		string number;
		number=k.getnumber();
		out << number;
		return out;
	}
int main() {
  string number1, number2;
  while (cin >> number1 >> number2) {
    BigInteger mBigInteger1(number1);
    BigInteger mBigInteger2(number2);
    
    cout << (mBigInteger1 + mBigInteger2) << endl; 
    mBigInteger2 += mBigInteger1;
    cout << mBigInteger2 << endl;
   cout << mBigInteger1++ << endl;
    cout << mBigInteger1 << endl;
    cout << ++mBigInteger1 << endl;
  }
  return 0;
}
