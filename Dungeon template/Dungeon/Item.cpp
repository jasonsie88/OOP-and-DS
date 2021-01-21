#include "Item.h"

    Item::Item(){}
    Item::Item(string name, int health, int attack, int defense){
        setName(name);
        this->health=health;
        this->attack=attack;
        this->defense=defense;
    }


    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    void Item:: triggerEvent(Object* object){
            Object* p=object;
            Player* play=dynamic_cast<Player*>(p);
            if(play){
             play->increaseStates(health,attack,defense);
             cout<<"You got a "<<this->getName()<<"!!"<<endl;
            }
            }

    /* Set & Get function*/
    int Item:: getHealth(){return health;}
    int Item:: getAttack(){return attack;}
    int Item:: getDefense(){return defense;}
    void Item:: setHealth(int health){ this->health=health;}
    void Item:: setAttack(int attack){this->attack=attack;}
    void Item:: setDefense(int defense){this->defense=defense;}
