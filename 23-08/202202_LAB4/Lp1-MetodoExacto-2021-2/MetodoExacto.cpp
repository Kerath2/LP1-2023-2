//
//  MetodoExacto.cpp
//  Lp1-MetodoExacto-2021-2
//
//  Created by gkerath on 24/08/23.
//

#include "MetodoExacto.hpp"


void CargaDeClientes(int *&cli_DNI, char **&cli_Nombre, char *&cli_Categoria){
    
    ifstream arch("Clientes.csv",ios::in);
    if(!arch){
        cout << "Error en la apertura del archivo clientes csv" << endl;
        exit(1);
    }
    
    /*
     71984468,IPARRAGUIRRE VILLEGAS NICOLAS EDILBERTO B,935441620
     29847168,ALDAVE ZEVALLOS ROSARIO A,6261108
     79475585,RETTO ARCA ANNIE MAGDA A,941241092
     */
    
    int buffDNI[100];
    char *buffNombre[100], buffCategoria[100] , car, basura[200];
    
    int cont = 0;
    while(1){
        arch >> buffDNI[cont];
        if(arch.eof()) break;
        arch >> car;
        leerCadena(arch,buffNombre[cont]);
        arch.getline(basura, 200 , '\n');
        cont++;
    }
    //Arreglando nombre y categoria
    separarDatos(buffNombre,buffCategoria,cont);
    
    //Asignamos la memoria a nuestros arreglos
    cli_DNI = new int[cont+1];
    cli_Nombre = new char*[cont+1];
    cli_Categoria = new char[cont+1];
    //Copiamos nuestros nuevos datos
    for (int i = 0 ; i < cont ; i++){
        cli_DNI[i] = buffDNI[i];
        cli_Nombre[i] = buffNombre[i];
        cli_Categoria[i] = buffCategoria[i];
        
    }
    //Agregamos terminadores
    cli_DNI[cont] = 0;
}

void leerCadena(ifstream &arch, char *&cad){
    char buff[200];
    arch.getline(buff,200,',');
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
}


void separarDatos( char *buffNombre[],char buffCategoria[], int cont ){
    /*
    IPARRAGUIRRE VILLEGAS NICOLAS EDILBERTO B
     */
    for (int i = 0 ; i < cont ; i++){
        char *nombre = buffNombre[i];
        buffCategoria[i] = nombre[strlen(nombre)-1];
        nombre[strlen(nombre)-2] = 0;
    }
    
}


void ReporteDeClientes(int *cli_DNI, char **cli_Nombre, char *&cli_Categoria){
    
    ofstream arch("Reporte_de_clientes.txt",ios::out);
    if(!arch){
        cout << "Error en la apertura del archivbo clienetes" << endl;
        exit(1);
    }
    for (int i = 0 ; cli_DNI[i]; i++){
        arch << setw(10) << cli_DNI[i] << setw(40) << cli_Nombre[i] << setw(6) << cli_Categoria[i] << endl;
    }
    
    
}


void CargaDePedidosYProductos(int *cli_DNI,int *&pro_Codigo,char **&pro_descripcion,double *&pro_Descuento,  double *&pro_Precio ,int **&cli_CodigoProFechaPedido, double **&cli_CantidadPedido){
    
    int codProd, duplicado = 0;
    int buffcod[200], vdni , dd , aa , mm;
    char *buffnom[200];
    double buffdesc[200] ,buffprec[200], aux, vdesc, vprecio;
    
    char car, descripcion[100];
    
    ifstream arch("Pedidos.csv",ios::in);
    if(!arch){
        cout << "Error en la apertura del archivo Pedidos.csv" << endl;
        exit(1);
    }
    
    int i = 0;
    while(1){
        arch >> codProd;
        if(arch.eof()) break;
        arch >> car;
        arch.getline(descripcion,100,',');
        arch >> aux;
        if(arch.fail()){
            arch.clear();
            arch >> car >> vdesc >> car >> aux;
        }
        else
            vdesc = 0;
        arch >> car >> vprecio >> car >> vdni >>car >> dd >> car >> mm >> car >> aa;
        
        
        duplicado = buscaProducto(codProd,buffcod,i);
        
    }
    
    cout << "todo bien" << endl;
    
}
        
int buscaProducto(int codProd,int buffcod[],int tam){
    for (int i = 0 ; buffcod[i] ; i++){
        if(codProd == buffcod[i])
            return 1;
    }
    return 0;
}
