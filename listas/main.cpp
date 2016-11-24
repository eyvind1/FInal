#include <iostream>
#include "listae.h"
using namespace std;

int main()
{
    Lista<int> a;
    Nodo<int>**p;
    a.ingresarNodo(20);
    //a.ingresarNodo(5);
    a.ingresarNodo(17);
    a.ingresarNodo(34);
    a.ingresarNodo(23);
    a.ingresarNodo(1);
    a.ingresarNodo(100);
    a.ingresarNodo(1345);
    a.mostrarLista();
    /*a.invertirPunteros();
    cout << endl;
    a.mostrarLista();
    a.invertirPunteros();*/
    cout << endl;
    a.borrarNodo(23);
    a.mostrarLista();
    cout<<a.buscar(100,p);

    return 0;
}
