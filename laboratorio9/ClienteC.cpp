/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClienteC.cpp
 * Author: Windows10
 * 
 * Created on 1 de noviembre de 2023, 22:27
 */

#include "ClienteC.h"

ClienteC::ClienteC() {
    flete = 0;
}

ClienteC::ClienteC(const ClienteC& orig) {
}

ClienteC::~ClienteC() {
}

void ClienteC::SetFlete(double flete) {
    this->flete = flete;
}

double ClienteC::GetFlete() const {
    return flete;
}

void ClienteC::lee(ifstream& arch, char categoria){
    arch >> flete;
    arch.get();
    SetFlete(flete);
    Cliente::lee(arch, categoria);
}