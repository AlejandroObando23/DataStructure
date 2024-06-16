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
public:
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
void encontrarDoctor(string idDoctor)
{

    while (cabeza != nullptr && cabeza->id != idDoctor)
    {
        cabeza = cabeza->sig;
    }
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
void verificar_disponibilidad()
{
    int opcion = 1;
    Turno* turnoActual = cabeza;

    cout << "\t---------------------------------------" << endl;
    cout << "\t| OPCION | HORA INICIO | HORA LLEGADA |" << endl;
    cout << "\t---------------------------------------" << endl;

    do
    {
        cout << "\t   " << opcion << "\t    " << turnoActual->horaInicio << ":00"
             << "\t" << turnoActual->horaFinal << ":00" << endl;
        turnoActual = turnoActual->sig;
        opcion++;
    }
    while (turnoActual != cabeza);

}
void modificarTurno() {
    int opcion;
    verificar_disponibilidad(); // Mostrar los turnos disponibles

    // Solicitar al usuario que seleccione un turno
    cout << "Seleccione el turno a modificar: ";
    cin >> opcion;

    // Encontrar el turno seleccionado
    Turno* turnoSeleccionado = cabeza;
    for (int i = 1; i < opcion && turnoSeleccionado != nullptr; ++i) {
        turnoSeleccionado = turnoSeleccionado->sig;
    }

    // Mostrar los detalles del turno seleccionado y solicitar nuevos valores
    if (turnoSeleccionado != nullptr) {
        cout << "\t------------------------------------" << endl;
        cout << "\t|        DETALLES DEL TURNO        |" << endl;
        cout << "\t------------------------------------" << endl;
        cout << "Hora de inicio actual: " << turnoSeleccionado->horaInicio << ":00" << endl;
        cout << "Hora de fin actual: " << turnoSeleccionado->horaFinal << ":00" << endl;

        int nuevaHoraInicio, nuevaHoraFinal;
        cout << "Ingrese nueva hora de inicio: ";
        cin >> nuevaHoraInicio;
        cout << "Ingrese nueva hora de fin: ";
        cin >> nuevaHoraFinal;

        turnoSeleccionado->horaInicio = nuevaHoraInicio;
        turnoSeleccionado->horaFinal = nuevaHoraFinal;

        cout << "Turno modificado exitosamente." << endl;
    } else {
        cout << "Opción de turno inválida." << endl;
    }
    system("pause");

}

void encontrarDoctor(string idDoctor, Persona*& doctorEncontrado)
{

    while (doctorEncontrado != nullptr && doctorEncontrado->id != idDoctor)
    {
        doctorEncontrado = doctorEncontrado->sig;
    }
}
void agregarTurno(Persona* inicioPersona)
{
    string idDoctor,nombre, apellido;
    int opcion;

    cout << "Ingrese el ID del Doctor: ";
    cin >> idDoctor;


    Persona* doctorEncontrado = nullptr;
    encontrarDoctor(idDoctor, inicioPersona);

    if (doctorEncontrado != nullptr)
    {
        cout << "\t------------------------------------" << endl;
        cout << "\t|    DATOS PERSONALES DEL DOCTOR   |" << endl;
        cout << "\t------------------------------------" << endl;
        cout << "ID registrado : " << doctorEncontrado->id << endl;
        cout << "NOMBRE        : " << doctorEncontrado->nombre << endl;
        cout << "APELLIDO      : " << doctorEncontrado->apellido << endl;
        cout << endl;

        // Mostrar los turnos disponibles
        verificar_disponibilidad();

        // Solicitar al usuario que seleccione un turno
        cout << "Seleccione un turno: ";
        cin >> opcion;

        // Encontrar el turno seleccionado
        Turno* turnoSeleccionado = cabeza;
        for (int i = 1; i < opcion && turnoSeleccionado != nullptr; ++i)
        {
            turnoSeleccionado = turnoSeleccionado->sig;
        }

        // Mostrar los detalles del turno seleccionado
        if (turnoSeleccionado != nullptr)
        {
            cout << "\t------------------------------------" << endl;
            cout << "\t|        DETALLES DEL TURNO        |" << endl;
            cout << "\t------------------------------------" << endl;
            cout<<endl;
            cout << "\t----------------------------------------------" << endl;
            cout << "\t| ID    | APELLIDO | NOMBRE  | INICIO  | FIN |" << endl;
            cout << "\t----------------------------------------------" << endl;
            cout << "\t " << doctorEncontrado->id << "  "
                 << doctorEncontrado->apellido << "  "
                 << doctorEncontrado->nombre << "  "
                 << turnoSeleccionado->horaInicio << ":00    "
                 << turnoSeleccionado->horaFinal << ":00 " << endl;

            turnoSeleccionado->doctor.id = doctorEncontrado->id;
            turnoSeleccionado->doctor.nombre = doctorEncontrado->nombre;
            turnoSeleccionado->doctor.apellido = doctorEncontrado->apellido;
        }
        else
        {
            cout << "Opción de turno inválida." << endl;
        }
    }
    else
    {
        cout << "No se encontro ningun doctor con ese ID." << endl;
    }
    system("pause");
}




};

