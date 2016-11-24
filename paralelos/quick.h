#ifndef QUICK_H
#define QUICK_H
#include <vector>
#include <thread>

using namespace std;

unsigned int num_nucleos;
vector<int> grandote;

void ordenar_quick_paralelo(int ini, int fin)
{
    int i=ini, j=fin, temporal;
    int piv=grandote[(ini+fin)/2];
    for(;i<=j;){
        for(;grandote[i]<piv;i++); // ubicando i en funcion a pivote elegido
        for(;grandote[j]>piv;j--);
        if(i<=j){
            //swaps para acomodar los lados derecho e izquierdo del pivote
            temporal=grandote[i];
            grandote[i]=grandote[j];
            grandote[j]=temporal;
            i++;
            j--;
        }
    }
    thread* m=nullptr, * n=nullptr;  // threads auxiliares para los procesos restantes
    if (i<fin)    {
        if(num_nucleos>0){
            num_nucleos-=1;
            m=new thread(ordenar_quick_paralelo,ini,j);//para que trabaje en un thread diferente
        }
        else ordenar_quick_paralelo(ini,j); //cuando no hay nucleos "disponibles", solo lo manda a un solo llamado

    }
    if (ini<j){
        if(num_nucleos>0){
            num_nucleos-=1;
            n=new thread(ordenar_quick_paralelo,i,fin);
        }
        else ordenar_quick_paralelo(i,fin);
    }
    if(m){
        m->join();
        num_nucleos+=1; // para que no me ningun error en el tiempo de compilacion
    }
    if(n){
        n->join();
        num_nucleos+=1;
    }
    delete(m);delete(n);
}

void quick_sort_paralelo(vector<int>& arreglo,int cores){
    num_nucleos=thread::hardware_concurrency();
    num_nucleos=cores;
    grandote=arreglo;
    thread hilo(ordenar_quick_paralelo,0,arreglo.size());
    hilo.join();
    arreglo=grandote;
}
#endif // QUICK_H
