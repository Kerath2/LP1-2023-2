
#ifndef Preg1_Funciones_de_cursos_y_alumnos_hpp
#define Preg1_Funciones_de_cursos_y_alumnos_hpp

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

void cargarCursosYEscalas ( char *** &cursos, double *& cursos_cred, double * escalas,const char *nombreCruso, const char *nombreEscala);


void leecursos(char ***& cursos,double *& cursos_cred,ifstream & archCurso);
void aumentarMemoria(char ***&cursos, double *&cursos_cred, int &numdat, int &capacidad);

char ** leeCurso(ifstream &archCurso, double &creditos);
#endif /* Preg1_Funciones_de_cursos_y_alumnos_hpp */
