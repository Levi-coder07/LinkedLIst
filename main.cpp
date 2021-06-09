#include <iostream>
using namespace std;
#include "linkedList.h"
int main(){
    LinkedList C;
    C.insert(5);
    C.insert(0);
    C.insert(1);
    C.insert(4);
    C.insert(6);
    C.insert(3);
    C.insert(0);
    C.insert(10);
    C.insert(7);
    C.insert(9);
    cout<<C<<endl;
    C.remove(2);
    cout<<C<<endl;
    C.insert(15);
    cout<<C<<endl;
    int x = 15;
    if(C.search(x)){
        cout<<"Elemento "<<x<< " encontrado";
    }else{
        cout<<"Elemento "<<x<< " no encontrado";
    }
    return 0;
}