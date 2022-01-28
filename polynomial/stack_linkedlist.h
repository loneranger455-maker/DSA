#include<iostream>
using namespace std;
template <class T>
class node{
    public:
    T value;
    node * next;


};
template <class TT>
class stack{
node<TT> *temp=NULL;
public:
void push(TT value){
    node<TT> *elm;
    elm=new(node<TT>);
    elm->value=value;
    elm->next=temp;
    temp=elm;
}
TT pop(){
    TT val;
node<TT>* temp2=new(node<TT>);
temp2=temp;
val=temp2->value;
temp=temp->next;
delete(temp2);
return(val);
}

TT top(){
    return(temp->value);
}

bool is_empty(){
    if(temp->next==NULL)
        return true;
    return false;
}
void display(){
    node<TT>* temp2=temp;
    while (temp2!=NULL)
    {
        cout<<temp2->value;
        temp2=temp2->next;

    }
    
}
};
