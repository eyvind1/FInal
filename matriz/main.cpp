#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include "Matrix.h"
using namespace std;

mutex ma;
/*void funcion_1()
{
    for(int i=0;i>-100;i--)
    {
        ma.lock();
        cout<<"from t1: "<<i<<endl;
        ma.unlock();
    }
}*/

int main()
{
    /*//mutex mu;
    thread t1(funcion_1);
    for(int i=0;i<100;i++)
    {
        ma.lock();
        cout<<"from main: "<<i<<endl;
        ma.unlock();
    }
    t1.join();*/
    Matrix a(4,4);
    a.llenar();
    //a.sumar_todo();
    //thread t1(&Matrix::arr_der,a);
    //t1.join();
    cout<<endl;
    //cout<<a.suma();
    cout<<endl;
    //
    /*thread t2(&Matrix::arr_izq,a);
    t2.join();
    thread t3(&Matrix::aba_der,a);
    t3.join();
    thread t4(&Matrix::aba_izq,a);
    t4.join();*/


   //thread t1(&Matrix::sumar_todo,&a);
   //t1.join();
   /* vector<thread>threads;
   for(int i = 0; i < 5; ++i){
           threads.push_back(thread(&Matrix::sumar_todo,&a));
           cout<<"soy thread"<<endl;
       }

    for(auto& thread : threads){
           thread.join();
       }*/

    cout<<a.suma();
    cout<<endl;

    a.imprimir();

    return 0;
}

