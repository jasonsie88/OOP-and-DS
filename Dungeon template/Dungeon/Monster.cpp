#include "Monster.h"

    Monster::Monster(){}
    Monster::Monster(string name,int currentHealth,int attack,int defense)
    {
        setName(name);
        setCurrentHealth(currentHealth);
        setAttack(attack);
        setDefense(defense);

    }
      /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
  void Monster:: triggerEvent(Object* object){
      Player* play=dynamic_cast<Player*>(object);
      if(play){
            int option;
            while(1){
            if(play->getCurrentHealth()<=0){
                cout<<"你輸了"<<endl;
                exit(0);
            }else if(this->getCurrentHealth()<=0){
                cout<<"你贏了"<<endl;
                break;
            }
            cout<<"選擇戰鬥或撤退?"<<endl;
            cout<<"(1) 戰鬥 (2) 撤退 "<<endl;
            cin>>option;
            switch(option){
            case 1:
            cout<<"你選擇戰鬥"<<endl;
            cout<<"你的攻擊造成"<<this->takeDamage(play->getAttack())<<"傷害"<<endl;
            cout<<this->getName()<<"的攻擊造成"<<play->takeDamage(this->getAttack())<<"傷害"<<endl;
            play->increaseStates((play->getCurrentHealth()-play->takeDamage(this->getAttack())),0,0);
            this->setCurrentHealth(this->getCurrentHealth()-this->takeDamage(play->getAttack()));
            break;
            case 2:
            play->changeRoom(play->getPreviousRoom());
            break;
            }
            }

      }
      }

    //}
