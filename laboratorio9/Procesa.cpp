/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Procesa.cpp
 * Author: Windows10
 * 
 * Created on 1 de noviembre de 2023, 22:51
 */

#include "Procesa.h"

Procesa::Procesa() {
}

Procesa::Procesa(const Procesa& orig) {
}

Procesa::~Procesa() {
}

void Procesa::carga(){
    cargarPedidos();
    cargaDeudores();
    
    
}


void Procesa::cargarPedidos(){
    ifstream arch("pedidos4.csv",ios::in);
    if(!arch){
        cout << "Error en la apertura del rachivo pediddos" << endl;
        exit(1);
    }
    
    int i = 0;
    while(1){
        lpedidos[i].leerPedido(arch);
        if(arch.eof())break;
        i++;
    }
    
    
}

void Procesa::cargaDeudores(){
    ifstream arch("clientes3.csv",ios::in);
    if(!arch){
        cout << "Error en la apertura de cleintes" << endl;
        exit(1);
    }
    
    int i = 0;
    while(1){
        ldeudor[i].leeDeudor(arch);
        if(arch.eof())break;
        i++;
    }
    
    
}