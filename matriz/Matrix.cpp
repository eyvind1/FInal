#include "Matrix.h"
#include <iostream>
#include <thread>
#include <mutex>
#include<future>
using namespace std;

mutex mu;

Matrix::Matrix(int f1,int c1):f(f1),c(c1)
{
    m=new int *[f1];
    for(int i=0;i<f;i++)
    {
        m[i]= new int [c];
    }
        for(int i=0;i<f;i++)
        {
            for(int j=0;j<c;j++)
            {
                m[i][j]=0;
            }
        }

}

Matrix::Matrix(const Matrix &a)
{
    f=a.f;
    c=a.c;
    m=new int *[f];
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            m[i][j]=a.m[i][j];
        }
    }
}


Matrix::~Matrix()
{
    for(int i=0;i<f;i++)
    {
        delete []m[i];
    }
    delete []m;
}


 int Matrix :: get (int f,int c)
{
    return m[f][c];
}

 void Matrix :: set (int f,int c, int a)
{
    m[f][c]=a;
}

void Matrix :: llenar ()
{
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>m[i][j];
        }
    }
}
void Matrix :: imprimir()
{
    for(int i=0;i<f;i++)
    {
        cout<<"\n";
        for(int j=0;j<c;j++)
        {
            cout<<m[i][j];
            cout<<"\t";
        }
    }
}

int Matrix :: suma()
{
    //thread t1;
    //thread t2;
    //thread t3;
    //thread t4;
    int a=0;
    int b=0;
    int e=0;
    int d=0;
    int total;
    thread t([&]()
    {
    for(int i=0;i<f/2;i++)
    {
        for(int j=0;j<c/2;j++)
        {
            a+=m[i][j];
        }
    }
    }
    );
    thread t1([&]()
    {
    for(int k=f/2;k<f;k++)
    {
        for(int l=0;l<c/2;l++)
        {
            b+=m[k][l];
            //cout<<m[k][l];
        }
    }
    }
    );
    thread t2([&]()
    {
    for(int r=0;r<f/2;r++)
    {
        for(int s=c/2;s<c;s++)
        {
            e+=m[r][s];

        }
    }
    }
    );
    thread t3([&]()
    {
    for(int p=f/2;p<f;p++)
    {
        for(int q=c/2;q<c;q++)
        {
            d+=m[p][q];
        }
    }
    }
    );

    t.join();
    t1.join();
    t2.join();
    t3.join();
    total=a+b+e+d;
    return total;

}


void Matrix :: arr_izq()
{
    int a;

    for(int i=0;i<f/2;i++)
    {
        for(int j=0;j<c/2;j++)
        {

            a+=m[i][j];

        }
    }
    cout<<a<<endl;

    //return a;
}

void Matrix :: arr_der()
{
    int e;
    for(int r=0;r<f/2;r++)
    {
        for(int s=c/2;s<c;s++)
        {

            e+=m[r][s];

        }
    }
    cout<<e<<endl;
    //return e;
}
void Matrix :: aba_izq()
{
    int b;
    for(int k=f/2;k<f;k++)
    {
        for(int l=0;l<c/2;l++)
        {
            b+=m[k][l];
            //cout<<m[k][l];
        }
    }
    cout<<b<<endl;
    //return b;
}
void Matrix :: aba_der()
{
    int d;
    for(int p=f/2;p<f;p++)
    {
        for(int q=c/2;q<c;q++)
        {
            d+=m[p][q];
        }
    }
    cout<<d<<endl;
    //return d;
}

/*void Matrix :: hilos()
{
    thread t1(&Matrix::arr_izq,this);
    cout<<"soy thread"<<endl;
    t1.join();


}*/

void Matrix :: sumar_todo()
{
    int suma=0;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            suma+=m[i][j];
        }
    }
    cout<<suma<<endl;
}
