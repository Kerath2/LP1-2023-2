/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClienteA.h
 * Author: Windows10
 *
 * Created on 1 de noviembre de 2023, 22:18
 */

#ifndef CLIENTEA_H
#define CLIENTEA_H

#include "Cliente.h"


class ClienteA : public Cliente {
public:
    ClienteA();
    ClienteA(const ClienteA& orig);
    virtual ~ClienteA();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch , char categoria);
private:
    double descuento;
};

#endif /* CLIENTEA_H */

