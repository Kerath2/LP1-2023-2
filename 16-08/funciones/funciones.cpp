#include "funciones.h"

 
double promedio(int * notas, int n ){
  int suma = 0;
  for (int i = 0 ; i < n ; i ++)
    suma += notas[i];
  
   return 1.0*suma/n;
}

double promedio(int n1 , int n2, int n3){
  int suma = n1 + n2 + n3;
  return 1.0 * suma / 3;
}


