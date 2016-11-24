#ifndef LIST_H
#define LIST_H
template <class T>
struct CNode
{
    CNode(T x)
    {
        m_data=x;
        m_next=0;
    }
    T m_data;
    CNode<T> *m_next;
};

template <class T>
class Lista
{
    public:
        Lista()
        {
            m_head=0;
        }
        virtual ~Lista();
        bool fiind(T x,CNode <T>** p);
        CNode<T> *m_head;

    protected:

    private:
};

#endif // LIST_H
