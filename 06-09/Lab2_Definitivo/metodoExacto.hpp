//
//  metodoExacto.hpp
//  Lab2_Definitivo
//
//  Created by gkerath on 7/09/23.
//

#ifndef metodoExacto_hpp
#define metodoExacto_hpp

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

void cargarDatos(int *&cli_dni,char **&cli_nombres,int ***&cli_pedidos);
void leerCadena(ifstream &arch, char *&cad);
int buscaPosicion(int dni,int * buff_dni,int cont);
int insertarOrdenado(int dni, char *nombre, int &cont, int *buff_dni, char **buff_Nombre, int ***buff_pedidos, int *numRegistros);
    


#endif /* metodoExacto_hpp */
