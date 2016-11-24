#ifndef TRAITS_H
#define TRAITS_H
template <class T>
struct CLess{
    inline bool operator()(T a, T b){
        return a<b;
    }
};
template <class T>
struct CGreather{
    inline bool operator()(T a, T b){
        return a>b;
    }
};

template <class T>
struct CListMayor{
    typedef T data_type;
    typedef CLess<data_type> cmp_type;
};

template <class T>
struct CListMenor{
    typedef T data_type;
    typedef CGreather<data_type> cmp_type;
};
#endif // TRAITS_H
