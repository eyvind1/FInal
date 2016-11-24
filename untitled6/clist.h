#ifndef CLIST_H
#define CLIST_H
#include <iostream>
using namespace std;

template <class T>
struct CNode{
    CNode(T x){
        m_data=x;
        m_next=nullptr;
    }
    T m_data;
    CNode<T> *m_next;
};

template <class Tr>
class CList{
public:
    typedef typename Tr::data_type T;
    typedef typename Tr::cmp_type C;
    C comparar;
    CNode<T>*m_head;
    CList(){
        m_head=0;
    }
    bool find(T x, CNode<T>** &p){
        for(p=&m_head;*p&& comparar(x,(*p)->m_data);p=&((*p)->m_next));
        return (*p) && x==(*p)->m_data;
    }
    bool insert (T x){
        CNode<T>**p;
        if (find(x, p)) return 0;
        CNode<T> *t=new CNode<T>(x);
        t->m_next=(*p);
        *p=t;
        return 1;
    }
    bool remove (T x){
        CNode<T> **p;
        if (!find(x, p)) return 0;
        CNode<T> *t=*p;
        *p=(*p)->m_next;
        delete t;
        return 1;
    }
    void imprimir (){
        for (CNode<T>*tem=m_head; tem!=nullptr; tem= tem->m_next ){
            cout<< tem->m_data<< " -> ";
        }
    }
};

#endif // CLIST_H
