#include "Record.h"
    Record::Record(){}
    void Record::saveToFile(Player* play, vector<Room>& room){
            ofstream outputFile1;
            ofstream outputFile2;
            outputFile1.open("recordOfPlayer.txt");
            outputFile2.open("recordOfRoom.txt");
            savePlayer(play,outputFile1);
            saveRooms(room,outputFile2);
            outputFile1.close();
            outputFile2.close();
    }
    void Record::loadFromFile(Player* play, vector<Room>& room){
            ifstream inputFile1;
            ifstream inputFile2;
            inputFile1.open("recordOfPlayer.txt");
            inputFile2.open("recordOfRoom.txt");
            loadPlayer(play,inputFile1);
            loadRooms(play,room,inputFile2);
            inputFile1.close();
            inputFile2.close();
    }

    void Record::savePlayer(Player* play, std::ofstream& outputFile){
            outputFile<<play->getAttack()<<endl;
            outputFile<<play->getCurrentHealth()<<endl;
            outputFile<<play->getMaxHealth()<<endl;
            outputFile<<play->getDefense()<<endl;
            outputFile<<play->getName()<<endl;
    }
    void Record::saveRooms(vector<Room>& room,std:: ofstream& outputFile){
            outputFile<<room.back().getIsExit()<<endl;
            outputFile<<room.back().getIndex()<<endl;
    }

    void Record::loadPlayer(Player* play, std::ifstream& inputFile){
            int attack,defense,maxHealth,currentHealth;
            string name;
            inputFile>>attack;
            play->setAttack(attack);
            inputFile>>currentHealth;
            play->setCurrentHealth(currentHealth);
            inputFile>>maxHealth;
            play->setMaxHealth(maxHealth);
            inputFile>>defense;
            play->setDefense(defense);
            inputFile>>name;
            play->setName(name);

    }
    void Record::loadRooms(Player* play,vector<Room>& room,std:: ifstream& inputFile){
            int index;
            bool exit;
            Room rooms;
            inputFile>>exit;
            inputFile>>index;
            play->setCurrentRoom(&room[index]);
            rooms.setIsExit(exit);
    }
