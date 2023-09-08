//

//


#include "metodoExacto.hpp"

int main(){

    int *cli_dni, ***cli_pedidos;
    char **cli_nombre;
    
    llenarClientes(cli_dni,cli_pedidos,cli_nombre);
    pruebaClientes("pruebaClientes.txt",cli_dni,cli_pedidos,cli_nombre);
    
    
}
