//
//  main.cpp
//  PRUEBA
//
//  Created by gkerath on 23/08/23.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "sobrecargas.h"
using namespace std;


int main(){
    ifstream archCur("Cursos.txt",ios::in);
    if(!archCur){
      cout << "Error en la apertura de los archivos cursos" << endl;
      exit(1);
    }
      
      ifstream archAlum("Alumnos.txt",ios::in);
      if(!archAlum){
          cout << "Error en la apertura del archivo alumnos" << endl;
          exit(1);
      }
      
      ifstream archMat("Matricula.txt",ios::in);
      if(!archMat){
          cout << "Error en la apertura del archivo matricula " << endl;
          exit(1);
      }

    // Se abrirar sin las cabecerar porque estoy en arm
      struct StCurso cursos[10], cur;
      archCur >> cursos[0];
      archCur >> cursos[1];
      strcpy(cursos[2].codigoDelCurso,"XXXXXX");
      archCur >> cur;
      cursos += cur;
      
     struct StAlumno alumnos[100], alu;
      archAlum >> alumnos[0];
      archAlum >> alumnos[1];
      alumnos[2].semestre = 0;
      archAlum >> alu;
      alumnos += alu;
      
      struct StRegistroDeMatricula matriculas[100], mat;
      archMat >> matriculas[0];
      archMat >> matriculas[1];

      strcpy(mat.codigoDelCurso,"MEC270");
      mat.codigodelAlumno=1397;
      mat.semestreDelAlumno=20211;
      
      cursos *= mat;
      cursos *= mat;

    
    
    return 0;
}
