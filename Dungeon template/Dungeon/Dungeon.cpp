#include "Dungeon.h"
    Dungeon::Dungeon(){}
    void Dungeon::createPlayer(){
        string name;
        cout << "�A�s����W�r?"<<endl;
        cin >> name;
        Player  p1ayer;
        player=Player(name,50,2000,100,0);
        this->player=player;
    }

    /* Create a map, which include several different rooms */
    void Dungeon::createMap(){
        int room_num=9;
        vector<Room> rooms;
        for(int i=0;i<room_num;i++){
            Room temp;
            temp.setIndex(i);
            rooms.push_back(temp);
        }
        vector<Object*>v0,v1,v2,v3,v4,v5,v6,v7,v8;
        vector<Item>c5;
        rooms[0]=Room(false,0,v0);
        rooms[1]=Room(false,1,v1);
        Item* super_sword=new Item("EA",200,200,200);
        v2.push_back(super_sword);
        rooms[2]=Room(false,2,v2);
        Monster* saber= new Monster("�ȷ��",200,100,50);
        v3.push_back(saber);
        rooms[3]=Room(false,3,v3);
        rooms[4]=Room(false,4,v4);
        Item* magic=new Item("���˶�",150,150,150);
        c5.push_back(*magic);
        NPC* caster=new NPC("���L","�ڬO���L�A�ڥi�H���Abuff",c5);
        v5.push_back(caster);
        rooms[5]=Room(false,5,v5);
        Item* excalibur=new Item("�t�C",200,200,25);
        v6.push_back(excalibur);
        rooms[6]=Room(false,6,v6);
        Monster* berserker= new Monster("���J�O�h",1000,150,5);
        v7.push_back(berserker);
        rooms[7]=Room(false,7,v7);
        rooms[8]=Room(true,8,v8);
        rooms[0].setUpRoom(&rooms[3]);
        rooms[0].setRightRoom(&rooms[1]);
        rooms[1].setUpRoom(&rooms[2]);
        rooms[1].setLeftRoom(&rooms[0]);
        rooms[2].setLeftRoom(&rooms[3]);
        rooms[2].setDownRoom(&rooms[1]);
        rooms[3].setUpRoom(&rooms[4]);
        rooms[3].setDownRoom(&rooms[0]);
        rooms[3].setRightRoom(&rooms[2]);
        rooms[4].setDownRoom(&rooms[3]);
        rooms[4].setLeftRoom(&rooms[5]);
        rooms[4].setUpRoom(&rooms[6]);
        rooms[5].setRightRoom(&rooms[4]);
        rooms[6].setUpRoom(&rooms[7]);
        rooms[6].setDownRoom(&rooms[4]);
        rooms[7].setUpRoom(&rooms[8]);
        rooms[7].setDownRoom(&rooms[6]);
        rooms[8].setDownRoom(&rooms[7]);
        this->rooms=rooms;

    }

    /* Deal with player's moveing action */
    void Dungeon::handleMovement(){
        int choices,index;
        Room* cur;
        Room* up;
        Room* down;
        Room* right;
        Room* left;
        cur=player.getCurrentRoom();
        index=cur->getIndex();
        cout<<"�A�b"<<index<<"���ж�"<<endl;
        up= cur->getUpRoom();
        down= cur->getDownRoom();
        right= cur->getRightRoom();
        left= cur->getLeftRoom();
        switch (player.getCurrentRoom()->getIndex()){
            case 0:
            cout << "�A�n�����̨�?"<<endl;
            cout <<  "(1) ���W (2) ���k"<<endl;
            cin >>choices;
                switch (choices){
                    case 1:
                    player.changeRoom(up);
                    break;
                    case 2:
                    player.changeRoom(right);
                    break;
            }
            break;
            case 1:
            cout << "�A�n�����̨�?"<<endl;
            cout <<"(1) ���W (2) ���� "<<endl;
            cin>>choices;
                switch(choices){
                    case 1:
                    player.changeRoom(up);
                    break;
                    case 2:
                    player.changeRoom(left);
                    break;
                }
            break;
            case 2:
            cout << "�A�n�����̨�?"<<endl;
            cout << "(1) ���U (2) ����"<<endl;
            cin>>choices;
                switch(choices){
                    case 1:
                    player.changeRoom(down);
                    break;
                    case 2:
                    player.changeRoom(left);
                    break;
                }
            break;
            case 3:
            cout << "�A�n�����̨�?"<<endl;
            cout << "(1) ���U (2) ���k (3) ���W"<<endl;
            cin>>choices;
                switch(choices){
                    case 1:
                    player.changeRoom(down);
                    break;
                    case 2:
                    player.changeRoom(right);
                    break;
                    case 3:
                    player.changeRoom(up);
                    break;
                }
            break;
            case 4:
            cout << "�A�n�����̨�?"<<endl;
            cout << "(1) ���W (2) ���� (3) ���U" <<endl;
            cin >>choices;
                switch(choices){
                    case 1:
                    player.changeRoom(up);
                    break;
                    case 2:
                    player.changeRoom(left);
                    break;
                    case 3:
                    player.changeRoom(down);
                    break;
                }
            break;
            case 5:
            cout << "�A�n�����̨�?"<<endl;
            cout << "(1) ���k"<<endl;
            cin >>choices;
                    switch(choices){
                        case 1:
                        player.changeRoom(right);
                        break;
                    }
            break;
            case 6:
            cout << "�A�n������?"<<endl;
            cout <<"(1) ���W (2) ���U"<<endl;
            cin>>choices;
                switch(choices){
                    case 1:
                    player.changeRoom(up);
                    break;
                    case 2:
                    player.changeRoom(down);
                    break;
                }
            break;
            case 7:
            cout << "�A�n������?"<<endl;
            cout <<"(1) ���U (2) ���W"<<endl;
            cin>>choices;
                switch(choices){
                case 1:
                player.changeRoom(down);
                break;
                case 2:
                player.changeRoom(up);
                break;
                }
            break;

        }
        }

    /* Deal with player's iteraction with objects in that room */


    void Dungeon::handleEvent(Object *object){
         int option;
         Record record;
         Room* cur;
         vector<Room>v0;
          Object *p=object;
          Monster *monster=dynamic_cast<Monster*>(p);
          Item *item=dynamic_cast<Item*>(p);
          NPC  *npc=dynamic_cast<NPC*>(p);
          if(item){
            cout<<"���@�ӹD��C�A�n�߰_�Ӷ�?"<<endl;
            cout<<"(1) �� (2) ����"<<endl;
            cin>>option;
            switch(option){
            case 1:
            item->triggerEvent(&player);
            cout<<"�A�Q�F��?"<<endl;
            cout <<"(1) �e�i (2) �T�{���A (3) �s�� (4) �h�X"<<endl;
            cin>>option;
            switch(option){
                case 1:
                handleMovement();
                break;
                case 2:
                player.triggerEvent(&player);
                handleMovement();
                break;
                case 3:
                cur=player.getCurrentRoom();
                v0.push_back(*cur);
                record.saveToFile(&player,v0);
                break;
                case 4:
                exit(0);
                break;
            }
            break;
            case 2:
             cout<<"�A�Q�F��?"<<endl;
            cout <<"(1) �e�i (2) �T�{���A (3) �s�� (4) �h�X"<<endl;
            cin>>option;
            switch(option){
                case 1:
                handleMovement();
                break;
                case 2:
                player.triggerEvent(&player);
                handleMovement();
                break;
                case 3:
                cur=player.getCurrentRoom();
                v0.push_back(*cur);
                record.saveToFile(&player,v0);
                break;
                case 4:
                exit(0);
                break;
            }
            break;
            }

          }else if(monster){
            monster->triggerEvent(&player);
            cout<<"�A�Q�F��?"<<endl;
            cout <<"(1) �e�i (2) �T�{���A (3) �s�� (4) �h�X"<<endl;
            cin>>option;
            switch(option){
                case 1:
                handleMovement();
                break;
                case 2:
                player.triggerEvent(&player);
                handleMovement();
                break;
                case 3:
                cur=player.getCurrentRoom();
                v0.push_back(*cur);
                record.saveToFile(&player,v0);
                break;
                case 4:
                exit(0);
                break;
            }


          }else if(npc){
            npc->triggerEvent(&player);
            cout<<"�A�Q�F��?"<<endl;
            cout <<"(1) �e�i (2) �T�{���A (3) �s�� (4) �h�X"<<endl;
            cin>>option;
            switch(option){
                case 1:
                handleMovement();
                break;
                case 2:
                player.triggerEvent(&player);
                handleMovement();
                break;
                case 3:
                cur=player.getCurrentRoom();
                v0.push_back(*cur);
                record.saveToFile(&player,v0);
                break;
                case 4:
                exit(0);
                break;
            }

          }

    }


    /* Deal with the player's action     */
    /* including showing the action list */
    /* that player can do at that room   */
    /* and dealing with player's input   */
    void Dungeon::chooseAction(vector<Object*> v ){
            int option;
            Room* cur;
            Record record;
            vector<Room> v0;
            if(!v.empty()){
                handleEvent(v.back());
            }else{
            cout<<"�A�Q�F��?"<<endl;
            cout <<"(1) �e�i (2) �T�{���A (3) �s�� (4)�h�X"<<endl;
            cin>>option;
            switch(option){
                case 1:
                handleMovement();
                break;
                case 2:
                player.triggerEvent(&player);
                break;
                case 3:
                cur=player.getCurrentRoom();
                v0.push_back(*cur);
                record.saveToFile(&player,v0);
                break;
                case 4:
                exit(0);
                break;
            }
    }
    }

    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void Dungeon::startGame(){
        cout << "�w��[�J�t�M�Ԫ�"<<endl;
        createPlayer();
        createMap();

    }

    bool Dungeon::checkGameLogic(){
        bool isExit;
        Room* cur;
        cur=player.getCurrentRoom();
        isExit=cur->getIsExit();
        if(isExit==true && player.getCurrentHealth()!=0){
            cout<<"�AĹ�o�F�t�M�A����!!!!!"<<endl;
            return true;
            exit(0);

        }else if(isExit==false && player.getCurrentHealth()<=0){
            cout << "�A��F"<<endl;
            return true;
            exit(0);
        }else{return false;}

    }
    /* Check whether the game should end or not */
    /* Including player victory, or he/she dead */


    /* Deal with the whole game process */
    void Dungeon::runDungeon(){
        int option;
        Record record;
        cout<<"�A�n�ϥΦs�ɶ�?"<<endl;
        cout<<"(1) ���n�A�}�ҷs�C��  (2) �n��"<<endl;
        cin>>option;
        switch(option){
        case 1:
            startGame();
            player.setCurrentRoom(&rooms[0]);
            while(1){
                Room* cur=player.getCurrentRoom();
                int index=cur->getIndex();
                chooseAction(rooms[index].getObjects());
                if(checkGameLogic()){
                        break;
                }
        }
        break;
        case 2:
        createMap();
        record.loadFromFile(&player,rooms);
        while(1){
            Room* cur=player.getCurrentRoom();
            int index=cur->getIndex();
            chooseAction(rooms[index].getObjects());
            if(checkGameLogic()){break;}
        }
        break;
        }
    }
