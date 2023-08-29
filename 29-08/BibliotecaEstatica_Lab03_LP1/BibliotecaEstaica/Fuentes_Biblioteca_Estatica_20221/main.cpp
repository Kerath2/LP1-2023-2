#include <iostream>
#include <fstream>
#include "Estructuras.h"
#include "Sobrecarga.hpp"

using namespace std;

int main(){
    ifstream archClientes("Clientes.txt",ios::in);
    if(!archClientes){
        cout << "Error en la apertura del archivo clientes" << endl;
        exit(1);
    }
    
    Estructura_ClienteRegistrado arrClientes[200];
    
    int i = 0;
    while(1){
        archClientes >> arrClientes[i];
        if(archClientes.eof()) break;
    }
    
    

    return 0;
}
