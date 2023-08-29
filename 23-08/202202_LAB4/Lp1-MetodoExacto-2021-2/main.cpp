
#include "MetodoExacto.hpp"



int main(){
    char **cli_nombre, *cli_Categoria, **pro_descripcion;
    int *cli_DNI, **cli_CodigoProFechaPedido, *pro_Codigo;
    double *pro_Precio, *pro_Descuento, **cli_CantidadPedido;
    
    CargaDeClientes(cli_DNI, cli_nombre, cli_Categoria);
    ReporteDeClientes(cli_DNI, cli_nombre, cli_Categoria);
    CargaDePedidosYProductos(cli_DNI, pro_Codigo, pro_descripcion, pro_Descuento, pro_Precio, cli_CodigoProFechaPedido, cli_CantidadPedido);
    
    
  return 0;
}

