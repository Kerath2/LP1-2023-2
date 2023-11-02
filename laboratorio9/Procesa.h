/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Procesa.h
 * Author: Windows10
 *
 * Created on 1 de noviembre de 2023, 22:51
 */

#ifndef PROCESA_H
#define PROCESA_H

#include "Pedido.h"
#include "Deudor.h"


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Procesa {
public:
    Procesa();
    Procesa(const Procesa& orig);
    virtual ~Procesa();   
    void carga();
    void cargarPedidos();
    void cargaDeudores();
private:
    Pedido lpedidos[200];
    Deudor ldeudor[200];
};

#endif /* PROCESA_H */

