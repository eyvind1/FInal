#include <iostream>
#include "listac.h"
using namespace std;

int main()
{
    LESCircular<int> c1;
    c1.insertar(2);
    c1.insertar(15);
    c1.insertar(2);
    c1.insertar(115);
    c1.insertar(22);
    c1.insertar(135);

    c1.imprimir();

    c1.borrar(2);
    c1.borrar(15);

    cout <<endl;
    c1.imprimir();
    return 0;
}
