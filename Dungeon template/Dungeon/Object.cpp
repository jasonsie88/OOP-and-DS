#include "Object.h"

    Object:: Object(){}
    Object:: Object(string name){
        this->name=name;
        }

    /* pure virtual function */
    void Object:: triggerEvent(Object* object) {};

    /* Set & Get function*/
    void Object:: setName(string name){this->name=name;}
    string Object:: getName(){return name;}

