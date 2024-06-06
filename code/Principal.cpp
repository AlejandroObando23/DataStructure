#include <iostream>
#include <string.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include "struct_PersonaTurno.h"
#include "Cargar_personas.h"
#include "Cargar_turno.h"

#define ANSI_BACKGROUND_BLUE "\033[44m"
#define ANSI_BACKGROUND_RESET "\033[0m"

using namespace std;


void cargar_personas(Persona<string,string,string> *&lista);

int escogerOpcion();
void mostrarMenuPrincipal(int opcionActual);
void mostar_Personas(Persona<string,string,string> *aux);
void mostar_Turnos(Turno<string,string> *aux);

int main(){

    bool salir = false;
    int opcion;

    do{
        opcion = escogerOpcion();
        Persona<string,string,string> *lista=nullptr;
        Turno<string,string> *listat=nullptr;
        cargar_personas(lista);
        cargar_turno(listat);


        switch(opcion){
        case 1:

            break;
        case 4:
            mostar_Personas(lista);
            break;
        case 5:
            mostar_Turnos(listat);
            break;

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
			case 72: opcionActual=(opcionActual>1)?opcionActual-1:6; break;
			case 80: opcionActual=opcionActual<6?opcionActual+1:1; break;
			case 13:system("cls");
					switch(opcionActual){
						case 1: return 1;break;
						case 2: return 2;break;
						case 3: return 3;break;
						case 4: return 4;break;
						case 5: return 5;break;
						case 6: return 6;break;
					};break;
			}
	}
}

void mostrarMenuPrincipal(int opcionActual){
    cout << "\t\t=== Bienvenido al sistema de Turnos ===" << endl;
    cout << "\n\tSeleccione una opcion:\n" << endl;

    for(int i=1;i<=6;i++){
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
			case 4: cout << "\t4. Ver lista de Personas" << endl;
                break;
			case 5: cout << "\t5. Ver lista de Turnos" << endl;
                break;
            case 6: cout << "\t6. Salir"<< endl;
                break;
			}
	}
	printf("%s",ANSI_BACKGROUND_RESET);
	cout << "\t==============" << endl;
}







void mostar_Turnos(Turno<string,string> *aux){

	cout<<"\t------LISTA DE Personas REGISTRADOS--------"<<endl;
	cout<<"\t==============================================================="<<endl;
	cout<<"\t| HORA INICIO | HORA LLEGADA |"<<endl;
	cout<<"\t==============================================================="<<endl;

            Turno<string,string> *turnoEncontrado = aux;
            while (turnoEncontrado != NULL) {
                turnoEncontrado = turnoEncontrado->sig;


            if (turnoEncontrado != NULL){
                cout << "\n\t" << turnoEncontrado->horaInicio<< "\t"<< turnoEncontrado->horaFinal<< "\t"<< endl;
            }

            }


    cout << "\n";
	system("pause");
}

void mostar_Personas(Persona<string,string,string> *aux){

	cout<<"\t------LISTA DE Personas REGISTRADOS--------"<<endl;
	cout<<"\t==============================================================="<<endl;
	cout<<"\t|   ID   |   NOMBRE   |   Apellido |"<<endl;
	cout<<"\t==============================================================="<<endl;

            Persona<string,string,string> *alumnoEncontrado = aux;
            while (alumnoEncontrado != NULL) {
                alumnoEncontrado = alumnoEncontrado->sig;


            if (alumnoEncontrado != NULL){
                cout << "\n\t" << alumnoEncontrado->id << "\t" << alumnoEncontrado->nombre <<"\t"<< alumnoEncontrado->apellido<< "\t"<< endl;
            }

            }


    cout << "\n";
	system("pause");
}

