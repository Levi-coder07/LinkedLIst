#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;
    struct nodo{
    int x;
    int cantidad;
    string code;
    char letra;
    struct nodo *sig;
    struct nodo *izq,*der;
    int nro;
    } ; 
    typedef struct nodo *ArbolBinario;
ArbolBinario crearNodo(char letra1,int x)
    {
    ArbolBinario nuevoNodo = new(struct nodo);
    nuevoNodo->cantidad = x;
    nuevoNodo->sig = NULL;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    nuevoNodo->letra = letra1;
    return nuevoNodo;
    }

    void comparar(ArbolBinario &arbol, char letra1)
{
    int cantidad=1;
    if(arbol==NULL){
        arbol = crearNodo(letra1,cantidad);
    }
    else if(arbol->letra!=letra1){
        comparar(arbol->sig, letra1);
    }
    else if(arbol->letra==letra1){
       arbol->cantidad++;
    }
}
 
void enOrden(ArbolBinario arbol)
{
    if(arbol!=NULL)
    {
    enOrden(arbol->izq);
    cout << arbol->cantidad << " ";
    enOrden(arbol->der);
 }
}
void mostrar(ArbolBinario arbol){
    
    if (arbol!=NULL){
        cout<<"["<<arbol->cantidad<<" , "<<arbol->letra<<"]"
        ;
    mostrar(arbol->sig);
    }
}
void crearArbol(ArbolBinario &arbol){
    
    while(arbol->sig!=NULL){
        nodo *new1;
        new1 = crearNodo(' ',arbol->cantidad+arbol->sig->cantidad);
        new1->izq = arbol;
        new1->der = arbol->sig;
        
        arbol = arbol->sig->sig;
        
        nodo *actual = arbol;
        if(actual==NULL){
            arbol = new1;
        }else{
             if(actual->sig==NULL){
            arbol->sig=new1;
        }else{
            while(actual->sig!=NULL){
            
            if(new1->cantidad<arbol->cantidad){
                nodo *temp3 = arbol;
                arbol = new1;
                arbol->sig = temp3;
            }else if(actual->cantidad<=new1->cantidad&&new1->cantidad<=actual->sig->cantidad){
                nodo *temp4 = actual->sig;
                actual->sig = new1;
                new1->sig = temp4;
            }else if(actual->sig==NULL){
                actual->sig = new1;
            }
            actual = actual->sig;
        }
        }
        }
       
        
        cout<<endl;
        mostrar(arbol);
        cout<<endl;
    }
}
void leer_datos(ArbolBinario &arbol){//Leer los datos de un archivo de texto plano
    const string leer = "leer.txt"; 
    char leer_letras;
    ifstream leer1;
    leer1.open(leer.c_str());
    while(!leer1.eof()){
        leer1>>leer_letras;
        if(leer_letras!='\0'){
            comparar(arbol,leer_letras);
        }
    
    }
}
void ordenar(ArbolBinario &arbol){//Algoritmo para ordenar la lista
    nodo *p = arbol;
    while(p!=NULL){
        nodo *j = p->sig;
        while(j!=NULL){
            if(p->cantidad>j->cantidad){
                int aux = j->cantidad;
                j->cantidad = p->cantidad;
                p->cantidad = aux;
                int aux1 = j->letra;
                j->letra = p->letra;
                p->letra = aux1;
            }
            j =  j->sig;
        }
        p = p->sig;
    }
    }

void readCadena(ArbolBinario arbol, string cadena){
    int size = cadena.length();
    bool fin;
    int i = 0;
    while(size!=0){
        
        nodo * actual = arbol;
        fin = true;
        
       
        while(fin !=false){
            if(cadena[i]==' '){
                cout<<" ";
                fin = false;
                size--;
                i++;
                break;
            }
            if(cadena[i] == '0'){
                actual = actual->izq;
                size--;
                if(actual->izq == NULL&&actual->der==NULL){
                    cout<<actual->letra;
                    fin = false;
                }
            }
            if(cadena[i] == '1'){
                actual = actual->der;
                size--;
                if(actual->izq == NULL&&actual->der==NULL){
                    cout<<actual->letra;
                    fin = false;
                }
            }
            i++;

        }
    }
    cout<<endl;
    
}
void inOrdenMostrar(ArbolBinario arbol) {
    if (arbol != NULL) {
        inOrdenMostrar(arbol->izq);       // Traverse the left subtree
        cout << arbol->cantidad << " ";  // Display the current node's data (or any other information you want to display)
        inOrdenMostrar(arbol->der);       // Traverse the right subtree
    }
}
void generarDotFile(ArbolBinario arbol, ofstream &dotFile) {
    if (arbol != NULL) {
        dotFile << arbol->cantidad  << "[label=\"" << arbol->cantidad << " , " << arbol->letra << "\"]" << endl;
        if (arbol->izq != NULL) {
            dotFile << arbol->cantidad << arbol->letra << " -> " << arbol->izq->cantidad << ";" << endl;
        }
        if (arbol->der != NULL) {
            dotFile << arbol->cantidad << arbol->letra << " -> " << arbol->der->cantidad  << ";" << endl;
        }
        generarDotFile(arbol->izq, dotFile);
        generarDotFile(arbol->der, dotFile);
    }
}

void visualizarArbol(ArbolBinario arbol) {
    ofstream dotFile("arbol.dot");
    dotFile << "digraph G {" << endl;
    generarDotFile(arbol, dotFile);
    dotFile << "}" << endl;
    dotFile.close();

    system("dot -Tpng arbol.dot -o arbol.png");
    system("start arbol.png");
}
int main(){
    int x;
    ArbolBinario calcular = NULL;
    leer_datos(calcular);
    ordenar(calcular);
    mostrar(calcular);
    crearArbol(calcular);
    cout<<endl;
    inOrdenMostrar(calcular);
    cout<<endl;
    //Reconocer las cadenas 
    string w1 = "000";
    string w2 = "100011001101 110001001101 110001001101 ";
    string w3 = "110001001101";
    cout<<"La cadena w1 " <<w1<<" : ";
    readCadena(calcular,w1);
    cout<<"La cadena w2 " <<w2<<" : ";
    readCadena(calcular,w2);
    cout<<"La cadena w3 " <<w3<<" : ";
    readCadena(calcular,w3);
    visualizarArbol(calcular);
   

    return 0;
}