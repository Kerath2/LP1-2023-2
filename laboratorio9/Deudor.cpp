/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Deudor.cpp
 * Author: Windows10
 * 
 * Created on 1 de noviembre de 2023, 22:39
 */

#include <cstddef>
#include "Deudor.h"

Deudor::Deudor() {
    this->Cdeudor = nullptr;
}

Deudor::Deudor(const Deudor& orig) {
}

Deudor::~Deudor() {
}

void Deudor::leeDeudor(ifstream& arch){
    char categoria;
    
    arch >> categoria;
    if(arch.eof()) return;
    arch.get(); // coma
    
    if(categoria == 'A') Cdeudor = new ClienteA;
    if(categoria == 'B') Cdeudor = new ClienteB;
    if(categoria == 'C') Cdeudor = new ClienteC;
    
    Cdeudor->lee(arch, categoria);
    
}