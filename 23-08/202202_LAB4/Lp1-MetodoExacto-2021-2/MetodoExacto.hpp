//
//  MetodoExacto.hpp
//  Lp1-MetodoExacto-2021-2
//
//  Created by gkerath on 24/08/23.
//

#ifndef MetodoExacto_hpp
#define MetodoExacto_hpp

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


void CargaDeClientes(int *&cli_DNI, char **&cli_Nombre, char *&cli_Categoria);
void leerCadena(ifstream &arch, char *&cad);
void separarDatos( char *buffNombre[],char buffCategoria[], int cont );
void ReporteDeClientes(int *cli_DNI, char **cli_Nombre, char *&cli_Categoria);
void CargaDePedidosYProductos(int *cli_DNI,int *&pro_Codigo,char **&pro_descripcion,double *&pro_Descuento,  double *&pro_Precio ,int **&cli_CodigoProFechaPedido, double **&cli_CantidadPedido);
int buscaProducto(int codProd,int buffcod[],int tam);
#endif /* MetodoExacto_hpp */
