//
//  metodoExacto.hpp
//  posibleLab2
//
//  Created by gkerath on 6/09/23.
//

#ifndef metodoExacto_hpp
#define metodoExacto_hpp

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;




void llenarClientes(int *&cli_dni,int ***&cli_pedidos,char **&cli_nombre);
void leerCadena(ifstream &arch, char *&cad);
int buscaPosicion(int dni,int * buff_dni,int cont);
int insertarOrdenado(int dni,char * nombre,int cont,int  *buff_dni,char **buff_Nombre);
void crearMemoria(int **& matriz);
void llenarRegistro(int & numRegistros,int **matriz, int codPed,int fecha);
void mocharRegistros(int ***buff_pedidos,int * numRegistros,int cont);





void pruebaClientes(const char * nombreArch ,int *cli_dni,int ***cli_pedidos,char **cli_nombre);
void imprimeRegistros(ofstream &arch, int **matriz);
#endif /* metodoExacto_hpp */
