#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include "matrix.h"
using namespace std;

mutex ma;


int main()
{

    Matrix a(4,4);
    a.llenar();

    cout<<endl;
    //cout<<a.suma();
    cout<<endl;

    vector<thread>threads;
   for(int i = 0; i < 5; ++i){
           threads.push_back(thread(&Matrix::sumar_todo,&a));
           cout<<"soy thread"<<endl;
       }

    for(auto& thread : threads){
           thread.join();
       }

    cout<<a.suma();
    cout<<endl;

    a.imprimir();

    return 0;
}

