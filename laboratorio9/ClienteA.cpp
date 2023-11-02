/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClienteA.cpp
 * Author: Windows10
 * 
 * Created on 1 de noviembre de 2023, 22:18
 */

#include "ClienteA.h"

ClienteA::ClienteA() {
    descuento = 0;
}

ClienteA::ClienteA(const ClienteA& orig) {
}

ClienteA::~ClienteA() {
}

void ClienteA::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double ClienteA::GetDescuento() const {
    return descuento;
}

void ClienteA::lee(ifstream& arch, char categoria){
    arch >> descuento;
    arch.get();
    
    SetDescuento(descuento);
    
    Cliente::lee(arch, categoria);
}