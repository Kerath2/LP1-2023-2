/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClienteB.h
 * Author: Windows10
 *
 * Created on 1 de noviembre de 2023, 22:25
 */

#ifndef CLIENTEB_H
#define CLIENTEB_H

#include "Cliente.h"


class ClienteB : public Cliente {
public:
    ClienteB();
    ClienteB(const ClienteB& orig);
    virtual ~ClienteB();
    void SetFlete(double flete);
    double GetFlete() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch , char categoria);
private:
    double descuento;
    double flete; 
};

#endif /* CLIENTEB_H */

