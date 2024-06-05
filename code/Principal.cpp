#include <iostream>
#include <string.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#define ANSI_BACKGROUND_BLUE "\033[44m"
#define ANSI_BACKGROUND_RESET "\033[0m"

using namespace std;

struct Persona{
    string id;
    string nombre;
    string apellido;
    Persona* sig;
};

struct Turno{
    string horaInicio;
    string horaFinal;
    Persona doctor;
    Turno* siguiente;
};
void cargar_personas();

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
			case 72: opcionActual=(opcionActual>1)?opcionActual-1:5; break;
			case 80: opcionActual=opcionActual<5?opcionActual+1:1; break;
			case 13:system("cls");
					switch(opcionActual){
						case 1: return 1;break;
						case 2: return 2;break;
						case 3: return 3;break;
						case 4: return 4;break;
						case 5: return 5;break;
					};break;
			}
	}
}

void mostrarMenuPrincipal(int opcionActual){
    cout << "\t\t=== Bienvenido al sistema de Turnos ===" << endl;
    cout << "\n\tSeleccione una opcion:\n" << endl;

    for(int i=1;i<=5;i++){
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
            case 5: cout << "\t5. Salir"<< endl;
                break;
			}
	}
	printf("%s",ANSI_BACKGROUND_RESET);
	cout << "\t==============" << endl;
}




void cargar_personas(Persona *&lista){
	ifstream archivo;

	archivo.open("Personas.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit (1);
	}

	while(!archivo.eof()){
		Persona *nuevo=new(Persona);

		archivo>>nuevo->id;
		archivo>>nuevo->nombre;
		archivo>>nuevo->apellido;
		nuevo->sig=nullptr;
		Persona *aux;

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


int Mostar_Personas(Persona *aux){

	cout<<"\t------LISTA DE Personas REGISTRADOS--------"<<endl;
	cout<<"\t==============================================================="<<endl;
	cout<<"\t|   ID   |   NOMBRE   |   Apellido |"<<endl;
	cout<<"\t==============================================================="<<endl;

            Persona *alumnoEncontrado = aux;
            while (alumnoEncontrado != NULL) {
                alumnoEncontrado = alumnoEncontrado->sig;


            if (alumnoEncontrado != NULL){
                cout << "\n\t" << alumnoEncontrado->id << "\t" << alumnoEncontrado->nombre << "\t"<< endl;
            }

            }


    cout << "\n";
	system("pause");
	return 1;
}
