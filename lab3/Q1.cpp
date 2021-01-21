#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
	Student( ) { }
	string generate_email(){
		string e_mail=first_name+"_"+last_name+"_";
		e_mail=e_mail+studentID+"@"+department;
		e_mail=e_mail+".nctu.edu.tw";
		return e_mail;	    	
    }
  	void getfirstname(string firstname){
  		first_name=firstname;
	  }
	void getlastname(string lastname){
		last_name=lastname;
	}
	void getstudentID(string student_ID){
		studentID=student_ID;
	}
	void getdepartment(string newdepartment){
		department=newdepartment;
	}
private:
	string first_name;
  	string last_name;
	string department;
	string studentID;
};


int main() {
  	Student mStudent;
  	string firstname;
  	string lastname;
  	string departname;
  	string studentID;
    cin >> firstname >>lastname >> departname>>studentID;
	mStudent.getfirstname(firstname);
	mStudent.getdepartment(departname);
	mStudent.getlastname(lastname);
	mStudent.getstudentID(studentID);  
  	cout << mStudent.generate_email() << endl;
    return 0;
}
