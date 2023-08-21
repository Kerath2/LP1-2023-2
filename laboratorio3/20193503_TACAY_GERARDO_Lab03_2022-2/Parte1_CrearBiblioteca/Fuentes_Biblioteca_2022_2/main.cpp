/*
 * Gerardo Miguel Tacay Terrazos
 * Codigo:20193503
 * 
 */

#include <iostream>
#include "Estructuras-202202.h"
#include "Sobrecargas.h"
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archMedicos("medicosLab3.txt",ios::in);
    if(!archMedicos){
	cout << "Error en la apertura del archivo medicos.txt" << endl;
	exit(1);
    }

    ifstream archPacientes("PacientesLab3.txt",ios::in);
    if(!archPacientes){
	cout << "Error en la apertura del archivo pacientes.txt" << endl;
	exit(1);
    }

    ifstream archCitas("ConsultasLab3.txt",ios::in);
    if(!archCitas){
	cout << "Error en la apertura del archivo Consultas.txt" << endl;
	exit(1);
    }

    StMedico medico;
    StPaciente paciente;
    StCita cita;

    StMedico arrMedicos[100];

 
//    
    int i = 0;
    while(1){
	archMedicos >> arrMedicos[i];	
	if(archMedicos.eof()) break;
	i++;
    }
   
//    while(1){
//	archPacientes >> paciente;
//	if(archPacientes.eof()) break;
//    }

    while(1){
	archCitas >> cita;
	if(archCitas.eof()) break;

	if(cita <= arrMedicos)
	    cout << "bien" << endl;	
    }
      
    return 0;
}

