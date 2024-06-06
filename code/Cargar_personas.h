#include<iostream>
#include <string.h>
#include <iostream>
#include <fstream>
void cargar_personas(Persona<string, string, string> *&lista){
	ifstream archivo;

	archivo.open("Personas.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit (1);
	}

	while(!archivo.eof()){
		Persona<string, string, string> *nuevo=new(Persona<string, string, string>);

		archivo>>nuevo->id;
		archivo>>nuevo->nombre;
		archivo>>nuevo->apellido;
		nuevo->sig=nullptr;
		Persona<string, string, string> *aux;

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
