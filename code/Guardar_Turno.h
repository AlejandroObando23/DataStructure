#include<iostream>
#include <string.h>
#include <fstream>
using namespace std;

template <typename T>
void guardarTurnoDoctor(T*& lista){
	ofstream archivo;
	int contador = 1, numElementos = 0, numElementosIngresados = 0;

	archivo.open("TurnosDoctor.txt",ios::out);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit (1);
	}

    T* aux = lista;

    do{
        if(aux->doctor.id != ""){
            numElementos++;
        }
        aux = aux->sig;
    }while(aux != lista);

    aux = lista;

	do{
		if(aux->doctor.id == ""){
			contador++;
			aux = aux->sig;
		}
		else{
            archivo << contador << "\t" << aux->doctor.id;
            contador++;
            numElementosIngresados++;
            if(numElementosIngresados < numElementos){
                archivo<<endl;
            }
            aux = aux->sig;
		}
	}while(aux != lista);
	archivo.close();
}
