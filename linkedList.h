#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "Node.h"
class LinkedList{
    private: 
        int size;
        Node *head;
    public:
        LinkedList();
        ~LinkedList();
        void insert(int x);
        void remove(int pos);
        friend std::ostream& operator <<(std::ostream &salida1,const LinkedList& C);
       
};
LinkedList::LinkedList(){
            this->head= nullptr;
            this->size = 0;
        }
LinkedList::~LinkedList(){
    Node * actual= head;
    Node * nextnode= nullptr;
    while(actual!=nullptr){
        nextnode = actual->next;
        delete actual;
        actual = nextnode;
    }
}
std::ostream& operator <<(std::ostream &salida1,const LinkedList& C){
    Node* actual = C.head; 
    while(actual!=nullptr){
        salida1 << actual->getValue()<<" ";
        actual = actual->getNextNode();
    }
    salida1 <<" [" <<C.size<<"]";
    return salida1;
}
void LinkedList::insert(int x){
    
    if(head ==nullptr){
        //caso donde la lista este vacia
        head = new Node(x);
    }   
    else {
        Node* actual = head;
        for(int i =0;i<size;i++){
            if(x<=actual->value){
                Node* temp = new Node(x);
                head = temp;
                temp->next= actual;
                break;
            }
            else if (actual->next!=nullptr){
                if (x>=actual->value&&x<=actual->next->value){
                Node* temp = new Node(x);
                Node* temp2 = actual->next;
                actual->next=temp;
                temp->next = temp2;
                break;
                }
            }
            else if(actual->next==nullptr) {
                Node* temp = new Node(x);
                actual->next=temp; 
            }
            actual = actual->next;
        }
    }
    ++size;

}

void LinkedList::remove(int pos){
    Node* actual = head;
    if(pos==0){
            head = actual->next;
            delete actual;
            size--;
            return;
    }
    for (int i=0;i<=size;i++){
        if(pos-1==i){
        //actual=actual->next;
        Node * actual2=actual->next;
        actual->next =actual2->next;
        delete actual2;
        break;
        }
        actual=actual->next;
        
    }
    size--;
}
#endif 