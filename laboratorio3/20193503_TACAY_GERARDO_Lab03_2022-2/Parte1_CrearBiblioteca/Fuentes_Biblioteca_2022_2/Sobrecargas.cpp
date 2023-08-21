


#include "Sobrecargas.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
bool operator>>(ifstream &arch, struct StMedico &medico){
	
//struct StMedico{
//    int codigo 🛫? -;
//    char nombre[60];
//    double tarifaPoxConsulta;
//    char especialidad[50];
//};

    //Asignando 0al codigo para ver si es el final
    medico.codigo = 0;
    
    char c,nombres[100];
    arch >> medico.codigo;
    if (arch.eof()) return false;
    arch >> ws;
    arch.getline(nombres,100,' ');
    arch >> medico.tarifaPoxConsulta;
   
    int cont = 0;
    for (int i = strlen(nombres) ; nombres[i]!= '_' ; i--)
	cont = i;

    int k = 0;
    for (int i = cont ; nombres[i] != 0 ; i++ ){
	medico.especialidad[k] = nombres[i];
	k++;
    }
    medico.especialidad[k] = 0;
    nombres[cont] = 0;
    strcpy(medico.nombre,nombres);
    return true;
}

bool operator>>(ifstream &arch, struct StPaciente &paciente){
//struct StPaciente{
//    int dni;
//    char nombre[60];
//	int telefono;
    //////////
//    struct StCita citas[20];
//    int numeroDeCitas;
//    double totalGastado;
//};
    arch >> paciente.dni;
    if(arch.eof()) return false;
    arch >> ws;
    arch.getline(paciente.nombre,60,' ');
    arch >> paciente.telefono;

    return true;
}


int operator>>(ifstream &arch, struct StCita&cita){
	
//struct StCita{
//    int codigoDelMedico;
//    int fecha;  // Fecha en el formato AAAAMMDD
////////////////////////////
//    double tarifaPorConsulta;
//    char especialidad[50];   
//};
    int dni, dd , mm ,aa;
    char c ;
    arch >> dni;
    if(arch.eof()) return -1;
    arch >> ws;
    arch >> cita.codigoDelMedico;
    arch >> dd >> c >> mm >> c >> aa; 
    cita.fecha = aa *10000 + mm *100 + dd;
    return dni;
}

bool operator <=(StCita cita, StMedico medico[]){

//struct StCita{
//    int codigoDelMedico;
//    int fecha;  // Fecha en el formato AAAAMMDD
////////////////////////////
//    double tarifaPorConsulta;
//    char especialidad[50];   
//};
//struct StMedico{
//    int codigo 🛫? -;
//    char nombre[60];
//    double tarifaPoxConsulta;
//    char especialidad[50];
//};

    for(int i = 0 ; medico[i].codigo ; i++){
	if(cita.codigoDelMedico == medico[i].codigo){
	   cita.tarifaPorConsulta = medico[i].tarifaPoxConsulta; 
	   strcpy(cita.especialidad,medico[i].especialidad);
	   return true;
	}
    } 
    return false;
}