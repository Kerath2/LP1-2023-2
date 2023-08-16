#include "funciones.h"

 
double promedio(int * notas, int n ){
  int suma = 0;
  for (int i = 0 ; i < n ; i ++)
    suma += notas[i];
  
   return 1.0*suma/n;
}


