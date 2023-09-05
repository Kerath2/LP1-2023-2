#include"MetodoDinamicoExacto.h"
  




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
