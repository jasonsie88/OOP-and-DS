#include <iostream>

using namespace std;

struct node
{
    float value;
    node *next;
};

class mStack
{
public:
    mStack();
    node *head;
    node *end;
    void push(float x);
    void pop();
    void print();
};

mStack::mStack()
{
    head = NULL;
    end = NULL;
}

void mStack::push(float x)
{
    node *temp=new node;
    temp->value=x;
    temp->next=head;
    head=temp;
    //push the element into the stack
}

void mStack::pop()
{
    if(head!=NULL)
        head=head->next;
    //pop the next element out of the stack
}

void mStack::print()
{
    mStack stackout=mStack();
    while(head!=NULL){
        stackout.push(head->value);
        head=head->next;
    }
    while(stackout.head!=NULL){
        cout<<stackout.head->value<<endl;
        stackout.head=stackout.head->next;
    }
    //print values from head to end
}

int main() {
    string order;
    mStack stack = mStack();
    while(cin>>order){
        if(order == "push"){
            float num;
            cin>>num;
            stack.push(num);
        }
        else if(order == "pop"){
            stack.pop();
        } 
    }
    
    stack.print();
    return 0;
}
