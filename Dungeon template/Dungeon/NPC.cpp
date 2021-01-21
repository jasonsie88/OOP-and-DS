#include "NPC.h"
    NPC::NPC(){}
    NPC::NPC(string name, string script, vector<Item> commodity){
            setScript(script);
            setName(name);
            setCommodity(commodity);
    }
    void NPC:: listCommodity(){
        for(int i=0;i<(int)commodity.size();i++){
            cout<<commodity[i].getName()<<" ";
        }
    } /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    void NPC:: triggerEvent(Object* object){
        Player* play=dynamic_cast<Player*>(object);
        int option;
        cout<<this->getScript()<<endl;
        cout<<"你想要得到阿瓦隆的力量嗎?"<<endl;
        cout<<"(1) Yes (2) No"<<endl;
        cin>>option;
        if(option==1){
            cout<<"你得到阿瓦隆的加護"<<endl;
            play->increaseStates(commodity.back().getHealth(),commodity.back().getAttack(),commodity.back().getDefense());
        }
    }

    /* Set & Get function*/
    void NPC:: setScript(string script){this->script=script;}
    void NPC:: setCommodity(vector<Item> commodity){this->commodity=commodity;}
    string NPC:: getScript(){return script;}
    vector<Item> NPC:: getCommodity(){return commodity;}
