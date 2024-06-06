#include<iostream>
#include <string.h>
#include <fstream>
using namespace std;

void cargar_turno(Turno*& lista){
	ifstream archivo;

	archivo.open("Turnos.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit (1);
	}

	while(!archivo.eof()){
		Turno* nuevo=new(Turno);

		archivo>>nuevo->horaInicio;
		archivo>>nuevo->horaFinal;
		nuevo->sig=nullptr;
		Turno* aux;

		if(lista==NULL){
			lista=nuevo;
		}
		else{
			aux=lista;
			while(aux->sig!=NULL){
				aux=aux->sig;
			}
			aux->sig=nuevo;
		}
	}

	archivo.close();
	return;
}
