//
//  metodoExacto.cpp
//  Lab2_Definitivo
//
//  Created by gkerath on 7/09/23.
//

#include "metodoExacto.hpp"

void cargarDatos(int *&cli_dni,char **&cli_nombres,int ***&cli_pedidos){
    ifstream arch("datosNuevo.csv",ios::in);
    if(!arch){
        cout << "Error en la apertura del archivo dato Neuvo" << endl;
        exit(1);
    }
    
    int dni, cont = 0, dd , mm ,aa, codPed, buff_dni[200]={};
    char *nombre, c,*buff_Nombre[200];
    int **buff_pedidos[200]={}, numRegistros[200]={};
    
    
    while(1){
        arch >> dni;
        if (arch.eof()) break;
        arch >> c;
        leerCadena(arch, nombre);
        arch >> codPed >> c >> dd >> c >> mm >> c >> aa;
        int fecha = aa * 10000 + mm *100 + dd;
        int posicion = buscaPosicion(dni,buff_dni,cont);
        if(posicion == -1){
            //desplaza los datos y coloca dni y nombre, todavia no coloca ningun registro
            posicion = insertarOrdenado(dni, nombre, cont , buff_dni, buff_Nombre, buff_pedidos, numRegistros);

        }
    }

}

void leerCadena(ifstream &arch, char *&cad){
    char buff[200];
    arch.getline(buff,200,',');
    cad = new char[strlen(buff) + 1];
    strcpy(cad,buff);
}
        

int buscaPosicion(int dni,int * buff_dni,int cont){
    for (int i  = 0 ; i < cont ; i++){
        if(buff_dni[i] == dni){
            return i;
        }
    }
    return -1;
}


int insertarOrdenado(int dni, char *nombre, int &cont, int *buff_dni, char **buff_Nombre, int ***buff_pedidos, int *numRegistros) {
    if (cont == 0) {
        buff_dni[0] = dni;
        buff_Nombre[0] = nombre;
        return 0;
    }

    int posaInsertar = cont;

    for (int i = 0; i < cont; i++) {
        if (dni < buff_dni[i]) {
            posaInsertar = i;
            break;
        }
    }

    for (int i = cont; i > posaInsertar; i--) {
        buff_dni[i] = buff_dni[i - 1];
        buff_Nombre[i] = buff_Nombre[i - 1];
        buff_pedidos[i] = buff_pedidos[i - 1];
        numRegistros[i] = numRegistros[i - 1];
    }

    buff_dni[posaInsertar] = dni;
    buff_Nombre[posaInsertar] = nombre;
    buff_pedidos[posaInsertar] = new int *[100];
    numRegistros[posaInsertar] = 0;

    cont++;

    return posaInsertar;
}
