#include <iostream>
#include "clist.h"
#include "traits.h"
using namespace std;

int main()
{
    CList<int> a;
    a.insert(4);
    a.imprimir();
    return 0;
}
