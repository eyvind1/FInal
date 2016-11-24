#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
public:
       Matrix();
       Matrix(const Matrix &a);
       Matrix(int f,int c);
       virtual ~Matrix();
       int get (int f,int c);
       void set (int f,int c, int a);
       void imprimir ();
       void llenar ();
       int suma();
       void arr_izq();
       void arr_der();
       void aba_izq();
       void aba_der();
       void hilos();
       void sumar_todo();
       Matrix operator + (Matrix &a);
   protected:
   private:
       int **m;
       int f;
       int c;
};

#endif // MATRIX_H
