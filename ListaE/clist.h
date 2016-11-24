#ifndef CLIST_H
#define CLIST_H
#include <iostream>
#include <sstream>
using namespace std;

template<typename T>
struct CNode {
    T m_data;
    CNode<T> *m_next;
    CNode(T x){
        m_data=x;
        m_next=0;
    }

};
template<class T>
class CList{
public:
    CNode<T> *m_head=nullptr;
    //CList();
    //~CList();
    bool find(T x, CNode<T>**&p){
        for (p=&m_head; *p && x<(*p)->m_data; p=&((*p)->m_next));
        return (*p)&&x==(*p)->m_data;
    }

    bool insert(T x){
        CNode<T>**p;
        if(find(x,p))
            return 0;
        CNode<T>*t=new CNode<T>(x);
        t->m_next=*p;
        *p=t;
        return 1;
    }
    void imprimir(){
        for (CNode<T>*tem=m_head; tem!=nullptr; tem=tem->m_next) {
            cout<<tem->m_data<<" -> ";
        }
        //cout<<m_head->m_data;
        cout<<endl;
        //cout<<m_head->m_data;
    }
    /*void imprimir1(){
     for (CNode<T>**tem=&m_head; (*tem)!=nullptr;tem=&((*tem)->m_next)) {
     cout<<(*tem)->m_data<<" -> ";
     }
     //cout<<m_head->m_data;
     }*/
    void invertir(){
        CNode<T>*temp,*prev,*next;
        temp=m_head;
        prev=0;
        while(temp!=nullptr){
            next=temp->m_next;
            temp->m_next=prev;
            prev=temp;
            temp=next;
        }
        m_head=prev;
    }
    bool remove(T x){
        CNode<T>**p;
        if (!find(x, p)) {
            return 0;
        }
        CNode<T>*t=*p;
        *p=(*p)->m_next;
        delete t;
        return 1;
    }

};

#endif // CLIST_H
