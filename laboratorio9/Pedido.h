/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Windows10
 *
 * Created on 1 de noviembre de 2023, 22:36
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    void leerPedido(ifstream &arch);
    
private:
    int codigo;
    int cantidad;
    int dni;
    int fecha;
    double total;
};

#endif /* PEDIDO_H */

