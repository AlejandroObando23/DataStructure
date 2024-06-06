#include<iostream>
#include <string.h>
#include <iostream>

#include <fstream>
void cargar_turno(Turno<string, string> *&lista){
	ifstream archivo;

	archivo.open("Turnos.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit (1);
	}

	while(!archivo.eof()){
		Turno<string, string> *nuevo=new(Turno<string, string>);

		archivo>>nuevo->horaInicio;
		archivo>>nuevo->horaFinal;
		nuevo->sig=nullptr;
		Turno<string, string> *aux;

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
