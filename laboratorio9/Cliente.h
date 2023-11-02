/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: Windows10
 *
 * Created on 1 de noviembre de 2023, 22:14
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetTotalped(double totalped);
    double GetTotalped() const;
    void SetCantped(int cantped);
    int GetCantped() const;
    void SetNombre(char* cad);
    void GetNombre(char *cad) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    virtual void lee(ifstream &arch , char categoria);
private:
    int dni;
    char categoria;
    char * nombre;
    int cantped;
    double totalped;
};

#endif /* CLIENTE_H */

