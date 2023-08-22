/*
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

#include "Estructuras-202202.h"
#include <fstream>
using namespace std;
bool operator>>(ifstream &arch, struct StMedico &medico);
bool operator>>(ifstream &arch, struct StPaciente &paciente);
int operator>>(ifstream &arch, struct StCita&cita);


bool operator <=(StCita cita, StMedico medico[]);
void operator+=(StPaciente paciente, StCita cita);
void operator++(StPaciente paciente);
#endif /* SOBRECARGAS_H */
