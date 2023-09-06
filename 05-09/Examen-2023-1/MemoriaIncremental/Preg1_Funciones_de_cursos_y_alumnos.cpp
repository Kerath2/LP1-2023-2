//
//  Preg1_Funciones_de_cursos_y_alumnos.cpp
//  MemoriaIncremental
//
//  Created by gkerath on 5/09/23.
//

#include "Preg1_Funciones_de_cursos_y_alumnos.hpp"
#define INCREMENTO 5



     

void cargarCursosYEscalas ( char *** &cursos, double *& cursos_cred, double * escalas,const char *nombreCruso, const char *nombreEscala){
    
    //Lo abro asi porque en arm no funcionan los .A del profesor Guanira
    ifstream archCurso("Cursos.csv",ios::in);
    if(!archCurso){
        cout << "Error en la apertura del archivo cursos" << endl;
        exit(1);
    }
    
    ifstream archEscalas("Escalas.csv",ios::in);
    if(!archEscalas){
        cout << "Error en la apertura del archivo escalas" << endl;
        exit(1);
    }
    
    
    leecursos(cursos,cursos_cred,archCurso);
    
}


void leecursos(char ***& cursos,double *& cursos_cred,ifstream & archCurso){
    int capacidad = 0, numdat = 0 ;
    char **registro;
    double creditos;
    cursos = nullptr;
    while(1){
        registro = leeCurso(archCurso, creditos);
        if(archCurso.eof()) break;
        if(numdat == capacidad){
            aumentarMemoria(cursos, cursos_cred , numdat , capacidad);
        }
        cursos[numdat - 1] = registro;
        cursos[numdat] = nullptr;
        cursos_cred[numdat - 1] = creditos;
        cursos_cred[numdat] = -1;
        numdat++;
    }
    
    
}

//Se peuden utilizar menos parametros.
//Es la formula de siempre para todos los ejercicios.
void aumentarMemoria(char ***&cursos, double *&cursos_cred, int &numdat, int &capacidad){
    
    char ***auxcurso;
    double *auxcred;
   
    
    capacidad+=INCREMENTO;
    if(cursos == nullptr){
        cursos = new char **[capacidad];
        cursos_cred = new double[capacidad];
        cursos[0] = nullptr;
        cursos_cred[0] = -1;
        numdat = 1;
    }else{
        auxcurso = new char **[capacidad];
        auxcred = new double[capacidad];
        for (int i = 0 ; i < numdat ;i++){
            auxcurso[i] = cursos[i];
            auxcred[i] = cursos_cred[i];
        }
        
        delete cursos;
        delete cursos_cred;
        
        cursos = auxcurso;
        cursos_cred = auxcred;
        
    }
}

    /*
     INF263,Algoritmia,3.75,35030611,INGA FLORES CESAR ADOLFO
     MEC270,Procesos De Manufactura,4,83265244,PAIRAZAMAN ALAMO MOISES MIGUEL
     */
char ** leeCurso(ifstream &archCurso, double &creditos){
    char buffcad[200], c , **curso;
    char *codcurso, *nomcurso , *nomprof;
    int codprof;
    
    archCurso.getline(buffcad, 200, ',');
    if(archCurso.eof()) return nullptr;
    codcurso = new char[strlen(buffcad) + 1];
    strcpy(codcurso,buffcad);
    
    
    archCurso.getline(buffcad, 200, ',');
    nomcurso= new char[strlen(buffcad) + 1];
    strcpy(nomcurso,buffcad);
    
    archCurso >> creditos >> c >> codprof >> c;
    
    archCurso.getline(buffcad, 200, ',');
    nomprof= new char[strlen(buffcad) + 1];
    strcpy(nomprof,buffcad);
    
    curso = new char*[3];
    curso[0] = codcurso;
    curso[1] = nomcurso;
    curso[2] = nomprof;
    
    
    return curso;
}
