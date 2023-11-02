/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Deudor.h
 * Author: Windows10
 *
 * Created on 1 de noviembre de 2023, 22:39
 */

#ifndef DEUDOR_H
#define DEUDOR_H

#include "Cliente.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Cliente.h"
#include "ClienteA.h"
#include "ClienteB.h"
#include "ClienteC.h"
class Deudor {
public:
    Deudor();
    Deudor(const Deudor& orig);
    virtual ~Deudor();
    
    void leeDeudor(ifstream &arch);
    
private:
    Cliente * Cdeudor;
};

#endif /* DEUDOR_H */

