#include "Player.h"
    Player:: Player(){};
    Player:: Player(string name,int currentHealth,int MaxHealth,int attack ,int defense):GameCharacter(name,currentHealth,MaxHealth,attack,defense)
    {

    }
    void Player:: addItem(Item item){inventory.push_back(item);}
    void Player:: increaseStates(int health,int attack,int defense){
         int newhealth,newattack,newdefense;
         newhealth=getCurrentHealth()+health;
         setCurrentHealth(newhealth);
         newattack=getAttack()+attack;
         setAttack(newattack);
         newdefense=getDefense()+defense;
         setDefense(newdefense);
    }
    void Player:: changeRoom(Room* room){
     setPreviousRoom(getCurrentRoom());
     setCurrentRoom(room);
    }

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
   void Player:: triggerEvent(Object* object){
            Player* play=dynamic_cast<Player*>(object);
        if(play){
            cout<<"Name: "<<this->getName()<<endl;
            cout<<"Health: "<<this->getCurrentHealth()<<"/"<<this->getMaxHealth()<<endl;
            cout<<"Attack: "<<this->getAttack()<<endl;
            cout<<"Defense: "<<this->getDefense()<<endl;

        }
   }

    /* Set & Get function*/

    void Player:: setCurrentRoom(Room* currentRoom){this->currentRoom=currentRoom;}
    void Player:: setPreviousRoom(Room* previousRoom){this->previousRoom=previousRoom;}
    void Player:: setInventory(vector<Item> inventory){this->inventory=inventory;}
    Room* Player:: getCurrentRoom(){return currentRoom;}
    Room* Player:: getPreviousRoom(){return previousRoom;}
    vector<Item> Player:: getInventory(){return inventory;}
