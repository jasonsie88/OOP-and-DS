#include "GameCharacter.h"

    GameCharacter::GameCharacter(){}
    GameCharacter::GameCharacter(string name,int currentHealth,int maxHealth,int attack,int defense):Object(name) {
        setMaxHealth(maxHealth);
        setCurrentHealth(currentHealth);
        setAttack(attack);
        setDefense(defense);
    }
    bool GameCharacter:: checkIsDead(){
        if(this->currentHealth<0){
            return true;
        }else{
            return false;
        }
    }
    int GameCharacter:: takeDamage(int hit){
        int damage;
        damage=hit-defense;
        if(damage>0){
            return damage;
        }else{
            return 0;
        }
    }

    /* Set & Get function*/
    void GameCharacter:: setMaxHealth(int maxHealth){this->maxHealth=maxHealth;}
    void GameCharacter:: setCurrentHealth(int currentHealth){this->currentHealth=currentHealth;}
    void GameCharacter:: setAttack(int attack){this->attack=attack;}
    void GameCharacter:: setDefense(int defense){this->defense=defense;}
    int GameCharacter:: getMaxHealth(){return maxHealth;}
    int GameCharacter:: getCurrentHealth(){return currentHealth;}
    int GameCharacter:: getAttack(){return attack;}
    int GameCharacter:: getDefense(){return defense;}
