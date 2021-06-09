#ifndef _NODE_H_
#define _NODE_H_

class Node{
        friend class LinkedList;
        int value;
        Node *next;
    public:
        Node(int x);
        ~Node();
        //friend std::ostream& operator <<(std::ostream &salida1,const LinkedList& C);
        void setNextNode(Node *next);
        void setValue(int value);
        Node* getNextNode();
        int getValue();

};
Node::Node(int x){
    this->value=x;
    this->next =nullptr;
}
Node::~Node(){
    
}
void Node::setNextNode(Node *next){
            this->next=next;
        }
void Node::setValue(int value){
            this->value=value;
}
Node* Node::getNextNode(){
    return next;
}
int Node::getValue(){
    return value;
}

#endif 