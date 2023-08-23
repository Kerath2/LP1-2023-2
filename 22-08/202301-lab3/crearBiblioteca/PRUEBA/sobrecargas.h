#ifndef SOBRECARGAS
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Estructuras.h"
using namespace std;

bool operator>>(ifstream & arch, StCurso &curso);
bool operator >>(ifstream &arch, struct StAlumno &alu);
bool operator >>(ifstream &arch, struct StRegistroDeMatricula &mat);
void operator+=(struct StCurso *arrCur ,struct StCurso &cur);
void operator+=(struct StAlumno *arralu , struct StAlumno &alu);
void operator *=(struct StCurso * arrCur, const struct StRegistroDeMatricula &reg);
#endif // !SOBRECARGAS

