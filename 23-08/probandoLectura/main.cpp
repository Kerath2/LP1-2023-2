#include <__errc>
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;


int main(){
  ifstream arch("entrada.txt",ios::in);
  if(!arch){
    cout << "Error en la apertura del archiv entrada.txt" << endl;
    exit(1);
  }
  
  char codCurso[10],c;
  int ciclo, codAlum;

  while(1){
    arch.getline(codCurso,10,',');
    if(arch.eof()) break;
    arch >> ciclo >> c >> codAlum;
    cout << codCurso << " " << ciclo << " " << codAlum << endl;
    arch >> ws;
  }


  return 0;
}
