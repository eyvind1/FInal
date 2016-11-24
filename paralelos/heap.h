#ifndef HEAP_H
#define HEAP_H

int numero_cores;
// elementos padres hijo izquierdo, hijo derecho
void monticulizar(vector<int>& heap,int i, int max) {

    int padre, hijo_izq, hijo_der;
    while(i < max) {
        padre = i;
        hijo_izq = (2*i) + 1; // ubicados la posicion diferente del padre
        hijo_der = hijo_izq + 1; // ubicados en la posicion diferente al padre pero a la derecha
        if( hijo_izq<max && heap[hijo_izq]>heap[padre] )   padre = hijo_izq;
        if( hijo_der<max && heap[hijo_der]>heap[padre] )       padre = hijo_der;
        if(padre == i) return;
        swap(heap[i],heap[padre]);
        i = padre;
    }
}

void al_monticulo(vector<int>& arr) {
    int i = (arr.size()/2) - 1;
    while(i >= 0) {
        monticulizar(arr, i, arr.size());
        --i;
    }
}



void ordenamiento_monticulos(vector<int>& arr, int cores) {
    numero_cores=cores;
    al_monticulo(arr); // lo arma, lo ordena como un tree
    int final = arr.size() - 1;
    int contador;
    while (final > 0) { // iteracion para que busque los padres cada vez
        swap(arr[0], arr[final]);//manda un ultimo elemento al final
        if(contador++<=numero_cores)
        {
            thread t=thread(monticulizar,ref(arr), 0, final);
            t.join();
        }
        else
            monticulizar(arr,0,final);
        --final;
    }
}
#endif // HEAP_H
