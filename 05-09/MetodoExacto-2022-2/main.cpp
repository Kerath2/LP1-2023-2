#include "MetodoDinamicoExacto.h"


//Borrar luegio
#include <iostream>
using namespace std;
//

int main(){

  char **med_Nombre, **med_Especialidad, **pac_Nombre;
  int *med_Codigo, *pac_DNI , **pac_Citas;
  double *med_Tarifa;


  lecturaDeMedicos("Medicos.csv",med_Codigo,med_Nombre, med_Especialidad, med_Tarifa);



  for(int i = 0 ; med_Codigo[i] ; i++){
    cout << med_Codigo[i] << " " << med_Nombre[i] << " " << med_Especialidad[i] << " " << med_Tarifa[i] << endl;
  }

  return 0;
}
