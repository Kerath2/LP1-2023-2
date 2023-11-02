/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClienteC.h
 * Author: Windows10
 *
 * Created on 1 de noviembre de 2023, 22:27
 */

#ifndef CLIENTEC_H
#define CLIENTEC_H

#include "Cliente.h"


class ClienteC : public Cliente{
public:
    ClienteC();
    ClienteC(const ClienteC& orig);
    virtual ~ClienteC();
    void SetFlete(double flete);
    double GetFlete() const;
    void lee(ifstream &arch , char categoria);
private:
    double flete;
};

#endif /* CLIENTEC_H */

