#include <iostream>
#include <iomanip>
#include "funciones.h"
using namespace std;

int main(){
  regNotas notas = {{1,2,3,4,5,6,7,8,9,10},10};
  // for (int i = 0 ; i < notas.n ; i++)
  //   cout << notas.lab[i] << endl;
  cout << promedio(notas.lab,10);


  return 0;
}
