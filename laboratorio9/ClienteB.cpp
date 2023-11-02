/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClienteB.cpp
 * Author: Windows10
 * 
 * Created on 1 de noviembre de 2023, 22:25
 */

#include "ClienteB.h"

ClienteB::ClienteB() {
    flete = 0;
    descuento = 0;
}

ClienteB::ClienteB(const ClienteB& orig) {
}

ClienteB::~ClienteB() {
}

void ClienteB::SetFlete(double flete) {
    this->flete = flete;
}

double ClienteB::GetFlete() const {
    return flete;
}

void ClienteB::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double ClienteB::GetDescuento() const {
    return descuento;
}

void ClienteB::lee(ifstream& arch, char categoria){
    char c;
    
    arch >> descuento >> c >> flete;
    arch.get();
    SetDescuento(descuento);
    SetFlete(flete);
    
    Cliente::lee(arch, categoria);
}