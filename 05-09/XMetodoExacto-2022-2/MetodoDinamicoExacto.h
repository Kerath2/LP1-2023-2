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
void lecturaDeCitas(const char * nombreArch, int *& pac_DNI, char ** &pac_Nombre, int **&pac_Citas);
void pruebaDeLecturaDeCitas(const char * nombreArch, int *pac_DNI, char ** pac_Nombre, int **pac_Citas);
int buscaIndice(int dni,int *buffpacDni,int cont);

void agregarDatos(int codMed,int fecha,int  * arregloPac, int cantDatos);
void mocharHorizontal(int *&arreglo , int cantDatos);
void imprimeCitas(ofstream &arch,int * citas );
#endif // !METODO_EXACOT

