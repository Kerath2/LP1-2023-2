#include"MetodoDinamicoExacto.h"
#include <iomanip>
  

#define TAM_LINEA 100



void lecturaDeMedicos(const char *nomberArch,int *& med_Codigo, char **&med_Nombre, char **& med_Especialidad,  double *&med_Tarifa){
  ifstream arch(nomberArch,ios::in);
  if(!arch){
    cout << "Error en la apertura para el archivo de lectura medicos" << endl;
    exit(1);
  }

  int buffCod[100];
  char *buffNombre[100], *buffEspecialidad[100];
  double buffTarifa[100];

  int cont = 0;
  while(1){
    arch >> buffCod[cont];
    if(arch.eof()) break;
    arch.get();
    leerCadena(arch, buffNombre[cont]);
    separaEspecialidad(buffNombre[cont],buffEspecialidad[cont]);
    arch >> buffTarifa[cont];
    cont++;
  }

  //Asignamos memoria a nuestros arreglos originales
  med_Codigo = new int[cont+1];
  med_Nombre = new char*[cont+1];
  med_Especialidad= new char*[cont+1];
  med_Tarifa = new double[cont+1];
  
  //Pasamos los datos
  
  for (int i = 0 ; i<cont ; i++){
    med_Codigo[i] = buffCod[i];
    med_Nombre[i] = buffNombre[i];
    med_Especialidad[i] = buffEspecialidad[i];
    med_Tarifa[i] = buffTarifa[i];
  }

  //Agregamos finalizadores
  med_Codigo[cont] = 0;




}

void leerCadena(ifstream &arch, char *&cad){
  char buff[200];
  arch.getline(buff,200,',');
  if(arch.eof()) return;
  cad = new char[strlen(buff)+1];
  strcpy(cad,buff);
}
    
void separaEspecialidad(char * nombre,  char * &especialidad){
  //NOmbre ya tiene memoria pero especialidad no tiene;
  //Encontramops el ultimo espacio
  int tam = strlen(nombre);
  int  posEspacio;
  for (int i = tam ; nombre[i] != ' ' ; i--)posEspacio = i;
  //En i esta el espacio
  //Asignemos neuva memoria

  especialidad = new char[tam -posEspacio +1];
//
  int i = 0 ;
  for(int j = posEspacio ; nombre[j] != 0 ; j++){
    especialidad[i] = nombre[j];
    i++;
  }
  especialidad[i] = 0;
  nombre[posEspacio] = 0;
}


void pruebaDeLecturaDeMedicos(const char *nomberArch,int *med_Codigo, char **med_Nombre, char **med_Especialidad,  double *med_Tarifa){
  ofstream arch(nomberArch,ios::out);
  if(!arch){
    cout << "Error en la apertura del archivo para prueba de lectura medicos" << endl;
    exit(1);
  }


  arch << fixed << setprecision(2) << left;
  for(int i = 0 ; med_Codigo[i] ; i++){
    arch << setw(12)  << med_Codigo[i] << setw(40) << med_Nombre[i] << setw(20) << med_Especialidad[i] << setw(12) << med_Tarifa[i] << endl;
  }


}
  

void lecturaDeCitas(const char * nombreArch, int *& pac_DNI, char ** &pac_Nombre, int **&pac_Citas){
  int buffpacDni[300], *buffpacCitas[300];
  char *buffpacNombre[300], c;

ifstream arch(nombreArch,ios::in);
  if(!arch){
    cout << "Error en la apertura del archivo para leer las citas" << endl;
    exit(1);
  }

  int dni, cont = 0, codMed, dd , mm ,aa, cantDatos[300] = {};
  char *nombre;
  while(1){
    arch >> dni;
    if(arch.eof()) break;
    arch >> c;
    leerCadena(arch,nombre);
    arch >> codMed >> c >> dd >> c >> mm >> c >> aa;
    int fecha = aa * 10000 + mm * 100 + dd;
    int indice  = buscaIndice(dni,buffpacDni,cont);
    if(indice == -1){
      buffpacDni[cont] = dni;
      buffpacNombre[cont] = nombre;
      //Creamos su fila horizontal inicializada en null
      buffpacCitas[cont] = new int[100];
      indice = cont;
      cont++;
    }
    // Agregamos el codmed y fecha para todos los casos
    agregarDatos(codMed,fecha,buffpacCitas[indice],cantDatos[indice]);
    cantDatos[indice]++;
  }
  //Mochamos los datos horizontalmente
  for (int i = 0 ; i < cont ; i++)
    mocharHorizontal(buffpacCitas[i] , cantDatos[i]);



  //Reservamos memoria para nuestros arreglos originales
  pac_DNI = new int[cont+1];
  pac_Nombre = new char*[cont+1];
  pac_Citas = new int*[cont+1];

  //Pasamos los datos
  for (int i = 0 ; i < cont ; i++){
    pac_DNI[i] = buffpacDni[i];
    pac_Nombre[i] = buffpacNombre[i];
    pac_Citas[i] = buffpacCitas[i];
  }
  //Terminador
  pac_DNI[cont]  = 0;
}

    

int buscaIndice(int dni,int *buffpacDni,int cont){
  for (int i = 0 ; i < cont ; i++){
    if( dni == buffpacDni[i])
      return i;
  }

  return -1;

}
    

void agregarDatos(int codMed,int fecha,int  * arregloPac, int cantDatos){
  arregloPac[2*cantDatos] = codMed;
  arregloPac[2*cantDatos + 1] = fecha;
}


void mocharHorizontal(int *&arreglo , int cantDatos){
  int *arrExacto = new int[cantDatos + 1];
  for (int i = 0 ; i < 2*cantDatos ; i++){
    arrExacto[i] = arreglo[i];
  }
  delete arreglo;
  arreglo = arrExacto;
  //Terminador
  arreglo[cantDatos*2] = 0;
}



void pruebaDeLecturaDeCitas(const char * nombreArch, int *pac_DNI, char ** pac_Nombre, int **pac_Citas){

  ofstream arch(nombreArch,ios::out);
  if(!arch){
    cout << "Error en la apertura del archivo para la  prueba de lectura de las citas" << endl;
    exit(1);
  }

  for (int i = 0 ;pac_DNI[i]; i++){
    arch << pac_DNI[i] << " " << pac_Nombre[i]<< ":" << endl;
    imprimeCitas(arch,pac_Citas[i]);
  }
}

void imprimeCitas(ofstream &arch,int * citas ){
  for (int i = 0 ; citas[i] != 0 ; i++){
    arch << citas[i] << " ";
  }
  arch << endl;
}




void reporteDeIngresosMedicosyGastosDeLosPacientes(const char *nombreArch,int *&med_Codigo,char **med_Nombre, char ** med_Especialidad,
                                                   double *med_Tarifa,int *pac_DNI,char **pac_Nombre,int **pac_Citas){

  ofstream arch(nombreArch,ios::out);
  if(!arch){
    cout << "Error en la apertura del archivo para el reporte final" << endl;
    exit(1);
  }

  arch << "EMPRESA PRESTADORA DE SALUD" << endl;
  imprimeLinea(arch,'=');
  arch << "INGRESOS DE LOS MEDICOS POR LAS CITAS:" << endl;
  imprimeLinea(arch,'=');
  arch << "N0. Codigo     Nombre            Especialidad               Tarifa           Total de Ingresos" << endl;
  imprimeLinea(arch, '-');
  arch << left << fixed << setprecision(2);
  for (int i = 0 ;  med_Codigo[i] ; i++){


    int repeticiones = encuentraRepeticiones(med_Codigo[i], pac_DNI, pac_Citas);
      double total = med_Tarifa[i] * repeticiones;


    arch <<setw(2) << i+1 << ")" << setw(12)  << med_Codigo[i] <<  setw(50) << med_Nombre[i] << setw(20) << med_Especialidad[i] << setw(12) << med_Tarifa[i]
      <<  right << setw(12) << total  <<   left << endl;
  }



}
  

void imprimeLinea(ofstream &arch,char car){
  for (int i = 0 ; i < TAM_LINEA ; i++){
    arch << car;
  }
  arch << endl;
}




int encuentraRepeticiones(int med_Codigo,int * pac_DNI,int ** pac_Citas){
  int repeticiones = 0;

  for (int i  = 0 ; pac_DNI[i] ;  i++){
    int *filaCitas = pac_Citas[i];
    for (int j = 0 ; filaCitas[j] ; j++)
      if(filaCitas[j] == med_Codigo) repeticiones++;
  }
  return repeticiones;
}
