#ifndef METODO_EXACOT
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

void separaEspecialidad(char * nombre,  char * &especialidad);
void leerCadena(ifstream &arch, char *&cad);
void lecturaDeMedicos(const char *nomberArch,int *& med_Codigo, char **&med_Nombre, char **& med_Especialidad,  double *&med_Tarifa);
void pruebaDeLecturaDeMedicos(const char *nomberArch,int *med_Codigo, char **med_Nombre, char **med_Especialidad,  double *med_Tarifa);

#endif // !METODO_EXACOT

