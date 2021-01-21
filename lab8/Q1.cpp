#include <iostream>
#include <string> 
using namespace std;

class Role {
public:
	string name;
	int level;
	int health;
	
	Role(string name, int level,int health){
		//TODO
		this -> name=name;
		this -> level=level;
		this -> health=health;
	}

    string get_status() {
        return "(" + name + ", " + to_string(level) + ", " + to_string(health) + ")";
    }
	
	string get_info(){
		return "Novice" + get_status();
	}
    virtual ~Role() = default;
};

class Saber : public Role {
public:
	Saber(string name, int level,int health) : Role(name, level, health){}
    string get_info(){
        return "Saber" + get_status();
    };
};

class Sorceress : public Role {
public:
	Sorceress(string name, int level,int health) : Role(name, level, health){}
    string get_info(){
        return "Sorceress" + get_status();
    };
};

void printInfo(Role *role) {
	//TODO
  	//Do casting and cout here
  	Role *p=role;
  	Saber *s1=dynamic_cast<Saber*>(p);
  	Sorceress *s2=dynamic_cast<Sorceress*>(p);
  	if(s1!=NULL){
  		cout << s1->get_info()<<endl;
    }else if(s2 !=NULL){
    	cout <<s2->get_info()<<endl;
	}
}

int main() { 
	
	//TODO
	string name1,name2;
	int level1,level2,health1,health2;
	cin >> name1 >>level1 >> health1;
	cin >> name2 >> level2 >> health2;
	Saber saber(name1,level1,health1);
	Sorceress sorceress(name2,level2,health2);
    printInfo(&saber);
    printInfo(&sorceress);

    return 0;
}
