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
                cout<<"�A��F"<<endl;
                exit(0);
            }else if(this->getCurrentHealth()<=0){
                cout<<"�AĹ�F"<<endl;
                break;
            }
            cout<<"��ܾ԰��κM�h?"<<endl;
            cout<<"(1) �԰� (2) �M�h "<<endl;
            cin>>option;
            switch(option){
            case 1:
            cout<<"�A��ܾ԰�"<<endl;
            cout<<"�A�������y��"<<this->takeDamage(play->getAttack())<<"�ˮ`"<<endl;
            cout<<this->getName()<<"�������y��"<<play->takeDamage(this->getAttack())<<"�ˮ`"<<endl;
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
