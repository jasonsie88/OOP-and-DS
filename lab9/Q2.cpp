#include <iostream>

using namespace std;

struct node
{
	float value;
	node *next;
};

class mQueue
{
public:
 	mQueue();
 	node *head;
 	node *end;
 	void push(float x);
 	void pop();
	void print();
};

mQueue::mQueue(){

    head = NULL;
    end = NULL;
}

void mQueue::push(float x)
{
    node* insert=new node;
    node* find=new node;
    insert->value=x;
    insert->next=end;
    if(head==NULL){
        head=insert;
    }
    else{
    find=head;
    while(find->next!=NULL){
        find=find->next;
    }
    find->next=insert;
    }
	//push the element into the queue
}

void mQueue::pop()
{

if(head!=NULL){
    head=head->next;
    }
	//pop the next element out of the queue
}
void mQueue::print()
{
     node *run=head;
    while(run!=NULL){
        cout<<run->value<<endl;
        run=run->next;
    }

    //print values from head to end
}

int main() {
    string order;
    mQueue queue = mQueue();
    while(cin>>order){
        if(order == "push"){
            float num;
            cin>>num;
            queue.push(num);
        }
        else if(order == "pop"){
            queue.pop();
        }
    }

    queue.print();
    return 0;
}
