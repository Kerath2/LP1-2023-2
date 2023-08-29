//
//  Sobrecarga.hpp
//  Fuentes_Biblioteca_Estatica_20221
//
//  Created by gkerath on 29/08/23.
//

#ifndef Sobrecarga_hpp
#define Sobrecarga_hpp

#include "Estructuras.h"
#include <fstream>
using namespace std;

ifstream & operator >>(ifstream &arch ,Estructura_ClienteRegistrado);

#endif /* Sobrecarga_hpp */
