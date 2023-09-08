//
//  metodoExacto.cpp
//  posibleLab2
//
//  Created by gkerath on 6/09/23.
//

#include "metodoExacto.hpp"


void llenarClientes(int *&cli_dni,int ***&cli_pedidos,char **&cli_nombre){
    ifstream arch("datosNuevo.csv",ios::in);
    if(!arch){
        cout << "Error en la apertura del archivo datos.csv" << endl;
        exit(1);
    }
    int cont = 0, dni, codPed , dd , mm ,aa ,buff_dni[200]={}, **buff_pedidos[200]={};
    int numRegistros[200] = {};
    char *nombre, c, *buff_Nombre[200];

    while(1){
        arch >> dni;
        if (arch.eof()) break;
        arch >> c;
        leerCadena(arch, nombre);
        arch >> codPed >> c >> dd >> c >> mm >> c >> aa;
        int fecha = aa * 10000 + mm *100 + dd;
        int posicion = buscaPosicion(dni,buff_dni,cont);
        if(posicion == -1){
            //Posicion Nueva
            posicion = insertarOrdenado(dni, nombre, cont , buff_dni, buff_Nombre, buff_pedidos, numRegistros);
            buff_pedidos[posicion] = new int *[100];
            cont++;
        }
        llenarRegistroOrdenado(numRegistros[posicion],buff_pedidos[posicion],codPed,fecha);
    }
    mocharRegistros(buff_pedidos,numRegistros,cont);
    //Crear memoria para nuestros buffers
    cli_dni = new int[cont+1];
    cli_nombre = new char*[cont+1];
    cli_pedidos = new int**[cont+1];
    
    //Copiar datos a nuestros buffers
    for (int i  = 0 ;  i < cont ;i++){
        cli_dni[i] = buff_dni[i];
        cli_nombre[i] = buff_Nombre[i];
        cli_pedidos[i] =  buff_pedidos[i];
    }
    
    //Terminadores
    cli_dni[cont] = 0;
    
    
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
    //buff_pedidos[posaInsertar] = new int *[100];
    numRegistros[posaInsertar] = 0;

    cont++;

    return posaInsertar;
}



void crearMemoria(int **& matriz){
    matriz = new int *[100];
}


void llenarRegistro(int & numRegistros,int **matriz, int codPed,int fecha){
    int *registro = new int[3]; // Crear un nuevo registro

    registro[0] = codPed;
    registro[1] = fecha;
    registro[2] = 0;

    matriz[numRegistros] = registro; // Asignar el nuevo registro a la matriz

    numRegistros++;
}



void llenarRegistroOrdenado(int &numRegistros, int **matriz, int codPed, int fecha) {
    int *registro = new int[3]; // Crear un nuevo registro

    registro[0] = codPed;
    registro[1] = fecha;
    registro[2] = 0;

    // Encontrar la posición adecuada para insertar el nuevo registro según la fecha
    int posicion = 0;
    while (posicion < numRegistros && matriz[posicion][1] <= fecha) {
        posicion++;
    }

    // Desplazar registros existentes para abrir espacio para el nuevo registro
    for (int i = numRegistros; i > posicion; i--) {
        matriz[i] = matriz[i - 1];
    }

    // Insertar el nuevo registro en la posición adecuada
    matriz[posicion] = registro;

    numRegistros++;
}

void mocharRegistros(int ***buff_pedidos,int * numRegistros,int cont){
    // Se asegura que exista nullptr en lugar del último registro
    for (int i = 0; i < cont; i++) {
        int **matriz = buff_pedidos[i];

        int **matrizNueva = new int *[numRegistros[i] + 1];
        for (int j = 0; j < numRegistros[i]; j++) {
            matrizNueva[j] = matriz[j];
        }

        delete[] matriz; // Elimina la matriz anterior
        matriz = matrizNueva;
        // Establece el último elemento como nullptr
        matriz[numRegistros[i]] = nullptr;

        buff_pedidos[i] = matriz; // Actualiza el puntero en buff_pedidos
    }
}



void pruebaClientes(const char * nombreArch ,int *cli_dni,int ***cli_pedidos,char **cli_nombre){
    ofstream arch(nombreArch,ios::out);
    if(!arch){
        cout << "Error en la apertura del archivo de reporte" << endl;
        exit(1);
    }
    
    arch << setw(50)  <<"REPORTE" << endl;
    for (int i = 0 ; cli_dni[i] ; i++){
        arch << "DNI: " << cli_dni[i] << "   " << "Nombre: " << cli_nombre[i] << endl;
        imprimeRegistros(arch,cli_pedidos[i]);
    }
    
}


void imprimeRegistros(ofstream &arch, int **matriz){
    for (int i = 0 ; matriz[i] != nullptr ; i++){
        int * registro = matriz[i];
        arch << registro[0] << " " << registro[1] << " " << registro[2] << endl;
    }
    arch << endl;
}


