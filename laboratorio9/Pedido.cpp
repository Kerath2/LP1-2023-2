/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Windows10
 * 
 * Created on 1 de noviembre de 2023, 22:36
 */

#include "Pedido.h"

Pedido::Pedido() {
    this->cantidad = 0;
    this->codigo = 0;
    this->dni = 0;
    this->fecha = 0 ;
    this->total = 0;
    
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}


void Pedido::leerPedido(ifstream& arch){
    int codLeido, cant, dd, mm, aa, fecha, dniLeido;
    double monto;
    char c;
    
    arch >> codLeido;
    if(arch.eof()) return;
    arch.get(); // coma
    
    arch >> cant >> c >> monto >> c >> dniLeido >> c >> dd >> c >> mm >> c >> aa;
    fecha = dd + mm*100 + aa*10000;
    
    SetCodigo(codLeido);
    SetCantidad(cant);
    SetDni(dniLeido);
    SetFecha(fecha);
    SetTotal(monto);
}