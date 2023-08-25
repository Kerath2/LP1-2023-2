
#include "MetodoExacto.hpp"



int main(){
    char **cli_nombre, *cli_Categoria, **pro_descripcion;
    int *cli_DNI, **cli_CodigoProFechaPedido, *pro_Codigo;
    double *pro_Precio, *pro_Descuento, **cli_CantidadPedido;
    
    CargaDeClientes(cli_DNI, cli_nombre, cli_Categoria);
    ReporteDeClientes(cli_DNI, cli_nombre, cli_Categoria);
    
  return 0;
}

