#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    string studentID;
    int score;
public:
    Student(){
    }
    Student(string name, string studentID, int score){
         Student:: name=name;
         Student:: studentID=studentID;
        Student:: score=score;
    }
  string getName(){
        return   Student::  name;
    }
    string getStudentID(){
        return  Student:: studentID;
    }
    int getScore(){
        return Student:: score;
    }
};

int main() {
    string name;
    string studentID;
    int score;
    Student mStudent;
    
    cin >> name >> studentID >> score;
    mStudent = Student(name, studentID, score);
    cout << mStudent.getName() << "'s studentID is " << mStudent.getStudentID()
    << " and score is " << mStudent.getScore() << "." << endl;
    
    return 0;
}
