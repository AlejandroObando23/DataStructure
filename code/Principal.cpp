#include <iostream>
#include <string.h>
#include <conio.h>
#define ANSI_BACKGROUND_BLUE "\033[44m"
#define ANSI_BACKGROUND_RESET "\033[0m"

using namespace std;

struct Persona{
    string id;
    string nombre;
    string apellido;
};

struct Turno{
    string horaInicio;
    string horaFinal;
    Persona doctor;
    Turno* siguiente;
};

int escogerOpcion();
void mostrarMenuPrincipal(int opcionActual);

int main(){

    bool salir = false;
    int opcion;

    do{
        opcion = escogerOpcion();

        switch(opcion){

        }

    }while(!salir);

    return 0;
}

int escogerOpcion(){
	int opcionActual=1;
	while(1){
		system("cls");
		mostrarMenuPrincipal(opcionActual);
		char tecla =_getch();
		switch(tecla){
			case 72: opcionActual=(opcionActual>1)?opcionActual-1:4; break;
			case 80: opcionActual=opcionActual<4?opcionActual+1:1; break;
			case 13:system("cls");
					switch(opcionActual){
						case 1: return 1;break;
						case 2: return 2;break;
						case 3: return 3;break;
						case 4: return 4;break;
					};break;
			}
	}
}

void mostrarMenuPrincipal(int opcionActual){
    cout << "\t\t=== Bienvenido al sistema de Turnos ===" << endl;
    cout << "\n\tSeleccione una opcion:\n" << endl;

    for(int i=1;i<=4;i++){
    	if(i==opcionActual){
    		printf("%s",ANSI_BACKGROUND_BLUE);
		}
		else{
			printf("%s",ANSI_BACKGROUND_RESET);
		}

		switch(i){
			case 1: cout << "\t1. Agregar Turno" << endl;
                break;
			case 2: cout << "\t2. Modificar Turno" << endl;
                break;
			case 3: cout << "\t3. Registrar Asistencia" << endl;
                break;
			case 4: cout << "\t4. Salir" << endl;
                break;
			}
	}
	printf("%s",ANSI_BACKGROUND_RESET);
	cout << "\t==============" << endl;
}
