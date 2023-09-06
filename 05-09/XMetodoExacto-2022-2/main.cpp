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
  pruebaDeLecturaDeMedicos("ReporteDeMedicos.txt",med_Codigo,med_Nombre, med_Especialidad, med_Tarifa);
  lecturaDeCitas("citas.csv",pac_DNI,pac_Nombre,pac_Citas);
  pruebaDeLecturaDeCitas("ReporteDeCitas.csv",pac_DNI,pac_Nombre,pac_Citas);





  return 0;
}
