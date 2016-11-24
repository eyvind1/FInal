#ifndef LISTAE_H
#define LISTAE_H
#include <iostream>
using namespace std;

template<class T>
struct Nodo
{
public:
    T dato;
    Nodo *sig;
    Nodo(T num)
    {
        this -> dato = num;
        sig = NULL;
    }
};



template<class T>
class Lista
{
private:

public:
    Lista();
    ~Lista();
    bool vacio();
    bool buscar(T x, Nodo <T> ** &p);
    bool ingresarNodo(T);
    bool borrarNodo(T);
    void mostrarLista();
    void invertirPunteros();
    Nodo<T> *head;

};

template<class T>
Lista<T>::Lista()
{
        head = NULL;
}

template<class T>
Lista<T>::~Lista()
{
    Nodo<T> *aux =  head;
    Nodo<T> *q = 0;

    while(aux != NULL)
    {
        q = aux->sig;
        delete aux;
        aux =q;
    }
}

template<class T>
bool Lista<T>::vacio()
{
    return(head == NULL);
}

template<class T>
bool Lista<T>::ingresarNodo(T numero)
{
    Nodo<T> **p;

    if(buscar(numero,p)) return 0;
    Nodo<T> *n =new Nodo <T>(numero);
    n->sig = *p;
    *p=n;
    return 1;
}

template<class T>
bool Lista<T>::borrarNodo(T x)
{
    Nodo<T>**p;
    if(!buscar(x,p)) return 0;
    Nodo <T> *t = *p;
    *p = t->sig;
    delete t;
    return 1;
}

template<class T>
void Lista<T>::mostrarLista()
{
   Nodo<T> *p = head;
   while(p != NULL)
   {
       cout << p->dato << endl;
       p=p->sig;
   }
}

template<class T>
bool Lista<T>::buscar(T x, Nodo <T> ** &p)
{
    for(p=&head; *p && x>(*p)->dato; p=&(*p)->sig);

    return *p && (*p)->dato ==x;
}

template<class T>
void Lista<T>::invertirPunteros()
{
    Nodo<T> *newHead;
    Nodo<T> *aux=head;
    Nodo<T> *auxAnt;

    while(aux->sig)
    {
        auxAnt=aux;
        aux = aux->sig;
    }
    newHead = aux;

    while(aux != head)
    {
        aux->sig = auxAnt;
        aux = aux->sig;
        auxAnt = head;
        while(auxAnt->sig != aux)
            auxAnt = auxAnt->sig;
    }
    head->sig = NULL;
    head =newHead;


}



#endif // LISTAE_H
