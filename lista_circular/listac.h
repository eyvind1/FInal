#ifndef LISTAC_H
#define LISTAC_H


#include <iostream>
using namespace std;

template <class T>
class Nodo
{
    public:
        Nodo(T x)
        {
            dato = x;
            sig = NULL;
        }
        Nodo<T> *sig;
        T dato;
    private:
};



#include <iostream>


using namespace std;
template <class T>
class LESCircular
{
    public:
        Nodo<T> *head;
        LESCircular(){head = NULL;}
        ~LESCircular()
        {
            /*T x;
            while(head)
            {
                x = head->dato;
                borrar(x);
            }*/

        }
        bool insertar(T x);
        bool borrar(T x);
        void imprimir();
        bool buscar(T x,Nodo<T> ** &p);

        void nodoFinal(Nodo<T> ** &q);

};

template <class T>
bool LESCircular<T>::insertar(T x)
{
    Nodo<T> **p;
    if(buscar(x,p)) return 0;
    Nodo<T> *n=new Nodo<T>(x);
    if(!!head)
        n->sig = (*p);
    else
        n->sig = n;
    *p=n;
    return 1;
}

template <class T>
bool LESCircular<T>::borrar(T x)
{
    Nodo<T> **p;

    if(!buscar(x,p)) return 0;
    Nodo<T> *d= *p;
    if(d==head)
    {
        Nodo<T> **q;
        nodoFinal(q);
        (*q)->sig = head->sig;
    }
    *p = d->sig;
    delete d;
    return 1;
}

template <class T>
void LESCircular<T>::imprimir()
{
    Nodo<T> *p=head;
    while(!!p && p->sig !=head)
    {
        cout << p->dato << endl;
        p=p->sig;
    }
    cout << p->dato << endl;

}

template <class T>
bool LESCircular<T>::buscar(T x,Nodo<T> ** &p)
{
    for(p= &head;!!(*p) && x != (*p)->dato && (*p)->sig != head ;p=&(*p)->sig);

    if(!!*p  && x != (*p)->dato )
        p=&(*p)->sig;

    return !!*p && (*p)->dato == x;
}

template <class T>
void LESCircular<T>::nodoFinal(Nodo<T>** &p)
{
    for(p= &head;!!(*p) && (*p)->sig != head ;p=&(*p)->sig);
}
#endif // LISTAC_H
