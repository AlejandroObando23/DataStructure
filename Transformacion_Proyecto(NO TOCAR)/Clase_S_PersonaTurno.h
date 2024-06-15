#include <iostream>
#include <string.h>
#include <iostream>
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

struct Persona
{
    string id;
    string nombre;
    string apellido;
    Persona* sig;
};
class ClasePersona
{
private:
    Persona* cabeza;
    Persona* fin;
public:

    ClasePersona():cabeza(NULL) {}

    ~ClasePersona()
    {
        while(cabeza != NULL)
        {
            Persona* temp= cabeza;
            cabeza=cabeza->sig;
            delete temp;

        }

    }
    void cargar_personas(){
    ifstream archivo;

	archivo.open("Personas.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit (1);
	}

	while(!archivo.eof()){
		Persona* nuevo=new(Persona);

		archivo>>nuevo->id;
		archivo>>nuevo->nombre;
		archivo>>nuevo->apellido;
		nuevo->sig=nullptr;
		Persona* aux;

		if(cabeza==NULL){
			cabeza=nuevo;
		}
		else{
			aux=cabeza;
			while(aux->sig!=NULL){
				aux=aux->sig;
			}
			aux->sig=nuevo;
		}
	}

	archivo.close();
	return;
    }

    void mostar_Personas()
{

    cout<<"\t------LISTA DE Personas REGISTRADOS--------"<<endl;
    cout<<"\t==============================================================="<<endl;
    cout<<"\t|   ID   |   NOMBRE   |   Apellido |"<<endl;
    cout<<"\t==============================================================="<<endl;

    Persona* alumnoEncontrado = cabeza;
    while (alumnoEncontrado != NULL)
    {
        alumnoEncontrado = alumnoEncontrado->sig;

        if (alumnoEncontrado != NULL)
        {
            cout << "\n\t" << alumnoEncontrado->id << "\t" << alumnoEncontrado->nombre <<"\t"<< alumnoEncontrado->apellido<< "\t"<< endl;
        }
    }
    cout << "\n";
    system("pause");
}




};
struct Turno
{
    int horaInicio;
    int horaFinal;
    Persona doctor;
    Persona *paciente;
    Turno* sig;

};
class ClaseTurno
{

public:
    Turno* cabeza;
    Turno* fin;
public:

    ClaseTurno():cabeza(NULL), fin(NULL) {}

    ~ClaseTurno()
    {
        while(cabeza != NULL)
        {
            Turno* temp= cabeza;
            cabeza=cabeza->sig;
            delete temp;

        }

    }
    void cargar_turno(){
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

		Turno* aux;

		if(cabeza==NULL){
			cabeza=nuevo;
			fin= nuevo;
			nuevo->sig = cabeza;
		}
		else{
            fin->sig=nuevo;
            nuevo->sig=cabeza;
            fin= nuevo;
		}
	}

	archivo.close();

}

void mostar_Turnos()
{

    cout<<"\t------LISTA DE Personas REGISTRADOS--------"<<endl;
    cout<<"\t==============================================================="<<endl;
    cout<<"\t| HORA INICIO | HORA LLEGADA |"<<endl;
    cout<<"\t==============================================================="<<endl;

    Turno* turnoEncontrado = cabeza;
    while (turnoEncontrado->sig != cabeza)
    {
        turnoEncontrado = turnoEncontrado->sig;


        if (turnoEncontrado != NULL)
        {
            cout << "\n\t    " << turnoEncontrado->horaInicio<< ":00" <<"\t"<< turnoEncontrado->horaFinal << ":00"<< "\t"<< endl;
        }
    }
    cout << "\n";
    system("pause");
}
void imprimirInfoTurno(Turno* turno ){


    if(cabeza != nullptr){
    cout << "\n\t======================================" << endl;
    cout << "\t== Turno Actual ==" << endl;
    cout << "\tHorario: " << turno->horaInicio << ":00 - " << turno->horaFinal << ":00 " << endl;
    cout << "\tEncargado: " << turno->doctor.nombre << " " << turno->doctor.apellido << endl;
    cout <<  "\tID: " << turno->doctor.id << endl;
    cout << "\t======================================\n" << endl;
    }
    else{
        cout << "\nLa lista esta vacia, listo para agregar turnos\n" << endl;
    }
}
};

