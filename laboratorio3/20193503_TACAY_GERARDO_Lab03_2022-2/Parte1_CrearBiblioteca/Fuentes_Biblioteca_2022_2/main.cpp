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

  //Realizando pruebas locas: 
  StCita arrCitas[500];
  StMedico arrMedicos[500];
  StPaciente arrPacientes[500];

  //Prueba de lecturas
  //Lecuta medicos
  int i = 0;
  while(archMedicos >> arrMedicos[i]) i++;
  arrMedicos[i].codigo = 0;
  //Lectura pacientes
  i = 0;
  while(archPacientes >> arrPacientes[i]) i++;
  //Lectura citas
  i = 0;
  while((archCitas >> arrCitas[i]) != -1) i++;

  //Busqueda
  if(arrCitas[0] <= arrMedicos) cout << "Encontrada info cita" << endl;
  else cout << "No encontrada info Cita" << endl;


  cout << arrCitas[0].codigoDelMedico << endl;

  //Agregacion
  //  //Antes tenemos que inicializar todas las citas del paciente 
  for (int i = 0 ; i < 20 ; i++)
    arrPacientes[0].citas[i].codigoDelMedico = 0;
  arrPacientes[0] += arrCitas[0];
  cout << "Se agrego correctamente la cita al paciente" << endl;
  cout << "Sus datos son: " << endl; 
  cout << arrPacientes[0].citas[0].codigoDelMedico << endl; 
  cout << arrPacientes[0].citas[0].fecha<< endl; 


    return 0;
}

