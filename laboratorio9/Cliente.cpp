/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: Windows10
 * 
 * Created on 1 de noviembre de 2023, 22:14
 */

#include "Cliente.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;
Cliente::Cliente() {
    this->cantped = 0;
    this->dni = 0;
    this->nombre =  nullptr;
    this->totalped = 0;
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
}

void Cliente::SetTotalped(double totalped) {
    this->totalped = totalped;
}

double Cliente::GetTotalped() const {
    return totalped;
}

void Cliente::SetCantped(int cantped) {
    this->cantped = cantped;
}

int Cliente::GetCantped() const {
    return cantped;
}

void Cliente::SetNombre(char* cad) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Cliente::GetNombre(char *cad) const {
    strcpy(cad,nombre);
}

void Cliente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char Cliente::GetCategoria() const {
    return categoria;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}


void Cliente::lee(ifstream& arch, char categoria){
    int dniLeido;
    char nombre[200];
    
    arch >> dniLeido;
    arch.get(); // coma
    arch.getline(nombre, 200);
    SetDni(dniLeido);
    SetCategoria(categoria);
    SetNombre(nombre);
    
}