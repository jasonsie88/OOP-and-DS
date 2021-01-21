#include "Room.h"
    Room::Room(){}
    Room::Room(bool isExit, int index, vector<Object*> objects){
        this->isExit=isExit;
        this->index=index;
        setObjects(objects);
    }
   // bool Room:: popObject(Object* ){


    //} /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/
    void Room:: setUpRoom(Room* room)
    {upRoom=room;}
    void Room:: setDownRoom(Room* room)
    {downRoom=room;}
    void Room:: setLeftRoom(Room* room)
    {leftRoom=room;}
    void Room:: setRightRoom(Room* room)
    {rightRoom=room;}
    void Room:: setIsExit(bool isexit){this->isExit=isExit;}
    void Room:: setIndex(int index){this->index=index;}
    void Room:: setObjects(vector<Object*> objects){this->objects=objects;}
    bool Room:: getIsExit(){return isExit;}
    int Room:: getIndex(){return index;}
    vector<Object*> Room:: getObjects(){return this->objects;}
    Room* Room:: getUpRoom(){ return upRoom;}
    Room* Room:: getDownRoom(){ return downRoom;}
    Room* Room:: getLeftRoom(){ return leftRoom;}
    Room* Room:: getRightRoom(){return rightRoom;}
