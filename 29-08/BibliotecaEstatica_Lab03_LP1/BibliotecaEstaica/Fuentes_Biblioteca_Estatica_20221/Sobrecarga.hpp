//
//  Sobrecarga.hpp
//  Fuentes_Biblioteca_Estatica_20221
//
//  Created by gkerath on 29/08/23.
//

#ifndef Sobrecarga_hpp
#define Sobrecarga_hpp

#include <fstream>
#include "Estructuras.h"
using namespace std;

ifstream & operator >>(ifstream &arch ,Estructura_ClienteRegistrado);
void leerCadena(ifstream &arch , char *&cad);

#endif /* Sobrecarga_hpp */
