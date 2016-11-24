#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template<class T>
struct CNode
{
    T m_data;
    CNode<T>* m_nodes[2];
    CNode(T x)
    {
        m_data=x;
        m_nodes[0]=m_nodes[1]=NULL;
    }
};


template <class T>
class CTree
{
    public:
    CNode<T>* m_root;
    bool find( T x, CNode<T>** &p );
    bool insert(T x);
    bool remove(T x);
    void imprimir(CNode<T> *p);
    void inorder(CNode<T> *p);
    void postorden(CNode<T> *p);
    void preorden(CNode<T> *p);
    void profundidad();
    void amplitud ();


    CTree()
    {
        m_root=NULL;
    }
};
template<class T>
bool CTree<T>::find(T x, CNode<T>**& p)
{
    for(p=&m_root;  (*p) && (*p)->m_data != x ; p=&( (*p)->m_nodes[ !( (*p)->m_data > x )]  ) );
    return (*p);
}
template<class T>
bool CTree<T>::insert(T x)
{
   CNode<T>**p;
    if(find(x,p)) return 0;
    *p=new CNode<T>(x);
    return 1;
}
template<class T>
CNode<T>** rep(CNode<T>**p)
{
    p = &(*p)->m_nodes[0];
    while( (*p)->m_nodes[1] != 0)
        p=&(*p)->m_nodes[1];
    return p;
}
template<class T>
bool CTree<T>::remove(T x)
{
    CNode<T>**p;
    if(!find(x,p))return 0;
    if((*p)->m_nodes[0] && (*p)->m_nodes[1])
    {
        CNode<T>**q= rep(p);
        (*p)->m_data= (*q)->m_data;
        p=q;
    }
    CNode<T>*t = *p;
    *p=(*p)->m_nodes[ (*p)->m_nodes[1] !=0 ];
    delete t;
    return 1;
}
template<class T>
void CTree<T>::imprimir(CNode<T> *p)
{
    if(p)
    {
        imprimir(p->m_nodes[0]);
        cout<<p->m_data<<" ";
        imprimir(p->m_nodes[1]);
    }
}

template<class T>
void CTree<T>::inorder(CNode<T> *p)
{
    if(p)
    {
        inorder(p->m_nodes[0]);
        cout<<p->m_data<<" ";
        inorder(p->m_nodes[1]);
    }
}

template<class T>
void CTree<T>::preorden(CNode<T> *p)
{
    if(p)
    {
        cout<<p->m_data<<" ";
        imprimir(p->m_nodes[0]);
        imprimir(p->m_nodes[1]);
    }
}

template<class T>
void CTree<T>::postorden(CNode<T> *p)
{
    if(p)
    {
        imprimir(p->m_nodes[0]);
        imprimir(p->m_nodes[1]);
        cout<<p->m_data<<" ";
    }

}

template<class T>
void CTree<T>::amplitud()
{
    queue<CNode<T>*> aux;
    aux.push( m_root );
    while(!aux.empty())
    {
        CNode<T>* p = aux.front();
        aux.pop();
        cout<< p->m_data<<" ";
        if(p->m_nodes[0]) aux.push(p->m_nodes[0]);
        if(p->m_nodes[1]) aux.push(p->m_nodes[1]);
    }
}
 template<class T>
void CTree<T>::profundidad()
{
    stack<CNode<T>*> pila;
    pila.push(m_root);
    while(!pila.empty())
    {
        CNode<T>* p = pila.top();
        pila.pop();
        cout<< p->m_data<<" ";
        if(p->m_nodes[0]) pila.push(p->m_nodes[0]);
        if(p->m_nodes[1]) pila.push(p->m_nodes[1]);
    }

}

int main()
{
    CTree<int> a;
    a.insert(23);
    a.insert(45);
    a.insert(67);
    a.insert(1);
    a.insert(5);
    a.insert(9);
    a.insert(10);
    a.insert(0);
    //cout<<a.m_root->m_data<<endl;
    cout<<"inorden"<<endl;
    a.inorder(a.m_root);
    cout<<endl;
    cout<<"preorden"<<endl;
    a.preorden(a.m_root);
    cout<<endl;
    cout<<"postorden"<<endl;
    a.postorden(a.m_root);
    cout<<endl;

    cout<<"amplitud"<<endl;
    a.amplitud();
    cout<<endl;

    cout<<"profundidad"<<endl;
    a.profundidad();
    a.remove(23);
    cout<<endl;
    cout<<"inorden"<<endl;
    a.inorder(a.m_root);
    cout<<endl;
    cout<<"preorden"<<endl;
    a.preorden(a.m_root);
    cout<<endl;
    cout<<"postorden"<<endl;
    a.postorden(a.m_root);
    cout<<endl;

    cout<<"amplitud"<<endl;
    a.amplitud();
    cout<<endl;

    cout<<"profundidad"<<endl;
    a.profundidad();
return 0;
}
