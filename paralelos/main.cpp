#include <iostream>
#include <vector>
#include <thread>
#include "quick.h"
#include "heap.h"
#include <time.h>
#include "merge.h"
#include <time.h>

using namespace std;


vector<int> grande;
vector<int> seleccionados;
int numero_nucleos;

int tam=100000;
int arreglo[100000];
//para el heap
int vector_final[100000];


void burbuja(vector<int>&arreglo,int ini,int fin)
{
    for(int i=ini;i<fin;i++)
    {
        int temp=0;
        for(int j=0;j<fin-(i);j++)
        {
            if(arreglo[temp]<arreglo[j])
                temp=j;
        }
        swap(arreglo[temp],arreglo[fin-(i+1)]);
    }
}

void seleccionar_elemento(int i,int j) // la metodologia es buscar un elemento lo mas grande posible
{
    int temporal=i;
    while(i<j)
    {
        if(grande[temporal]<grande[i])
            temporal=i;
        i++;
    }
    seleccionados.push_back(temporal);
}

void burbuja_paralalelo(int i)
{
    vector<thread> hebras;
    int razon=i/numero_nucleos;

    for(int p=0;p<numero_nucleos-1;p++)
    {
        //lo mas factible es que cada nucleo busque elementos grandes
        hebras.push_back(thread(seleccionar_elemento,p*razon,(p+1)*razon));
    }
    hebras.push_back(thread(seleccionar_elemento,(numero_nucleos-1)*razon,i));

    for(unsigned int p=0;p<hebras.size();p++)
        hebras[p].join();
}

void ordenamiento_burbuja_paralelo(vector<int>& arreglo, int cores)
{
    numero_nucleos=thread::hardware_concurrency();
    numero_nucleos=cores;
    grande=arreglo;
    for(int i=grande.size();i>numero_nucleos;i--)
    {
        burbuja_paralalelo(i);
        int temporal=0;

        for(int po=0;po<numero_nucleos;po++)
        {
            // compara entre mis elementos seleccionados, temp=mayor de todos
            if(grande[seleccionados[temporal]]<grande[seleccionados[po]])
                temporal=po;
        }
        swap(grande[seleccionados[temporal]],grande[i-1]);
        seleccionados.clear();
    }
    burbuja(grande,0,numero_nucleos);
    arreglo=grande;
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}



int main(){

    int arr[100] ;
    int aleatorios;
    vector<int>a;
    srand (time(NULL));
    for(int i=0;i<100;i++)
    {
        aleatorios=rand()%100;
        a.push_back(aleatorios);
    }
    for(int i=0;i<a.size();i++)
    {
         cout<<a[i]<<" ";
     }
    cout<<endl;
    cout<<"#########";
    cout<<endl;
    ordenamiento_burbuja_paralelo(a, 4);
    //quick_sort_paralelo(a,4);
    //ordenamiento_monticulos(a,4);

    for(int i=0;i<a.size();i++)
    {
         cout<<a[i]<<" ";
     }

    /*for(int i=0;i<100;i++)
    {
        arr[i]=rand()%100;
    }
    printArray(arr,100);
    cout<<endl;
    mergesort_paralelo(arr, 0, 99,4);
    printArray(arr,100);*/
    return 0;

}
