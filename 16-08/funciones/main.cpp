#include <iostream>
#include <iomanip>
#include "funciones.h"
#include <iomanip>

using namespace std;

int main(){
  regNotas notas = {{1,2,3,4,5,6,7,8,9,10},10};
  // for (int i = 0 ; i < notas.n ; i++)
  //   cout << notas.lab[i] << endl;
  cout << setw(10) << fixed << setprecision(2) << promedio(notas.lab,10) << endl;
  cout << setw(10) << promedio(10,11,12);


  return 0;
}
