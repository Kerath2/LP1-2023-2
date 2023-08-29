//
//  Sobrecarga.cpp
//  Fuentes_Biblioteca_Estatica_20221
//
//  Created by gkerath on 29/08/23.
//

#include "Sobrecarga.hpp"
#include <fstream>
using namespace std;

ifstream & operator >>(ifstream &arch, Estructura_ClienteRegistrado &cliente) {
   /*
    71984468   IPARRAGUIRRE_VILLEGAS_NICOLAS_EDILBERTO-B      935441620
    29847168    ALDAVE_ZEVALLOS_ROSARIO-A     6261108
    79475585      RETTO_ARCA_ANNIE_MAGDA-A  941241092
    */
    
    /*
     DNI NOMBRE CATEGORIA TELEFONO
     */
    int telefono;
    
    arch >> cliente.dni;
//  if(arch.eof()) return;
    arch.getline(cliente.nombre,80,',');
    arch >> telefono;
    
    return arch;
}

void leerCadena(ifstream &arch , char *&cad){
    char buff[200];
    arch.getline(buff,200,',');
    cad = new char[strlen(buff)+ 1];
    strcpy(cad,buff);
}

