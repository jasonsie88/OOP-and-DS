#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Object
{
private:
    string name;
public:
    Object();
    Object(string);

    /* pure virtual function */
    virtual void triggerEvent(Object*) = 0;

    /* Set & Get function*/
    void setName(string);
    string getName();
};

#endif // OBJECT_H_INCLUDED
