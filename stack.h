#ifndef stack_h
#define stack_h
#include "node.h"
class Stack {
	NodePtr top;
	int size;
public:
    void push(int);
    int pop();
    Stack();
    ~Stack();
};


void Stack::push(int x){
  NodePtr new_node=new NODE(x);
  if(new_node){
    new_node->set_next(top);
    top = new_node;
    size++;
  }
}

int Stack::pop(){
    NodePtr t=top;
    if(t!=NULL){
        int value=t->get_value();
        top = t->get_next();
        size--;
        delete t;
        cout << value << endl;
        return value;
    }
    cout<<"Empty stack"<<endl;
    return 0;
}

Stack::Stack(){
    top=NULL;
    size=0;
}

Stack::~Stack(){
    cout<<"Clear the stack"<<endl;
    while(size>0) pop();
}

#endif