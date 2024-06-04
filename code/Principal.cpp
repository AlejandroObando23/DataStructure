#include <isotream>
#include <string.h>
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

int main(){

    do{
        cout << "\t=== Bienvenido al sistema de Turnos ===" << endl;
        cout << "Seleccione una opción:" << endl;
        cout << "1. Agregar Turno" << endl;
        cout << "2. Modificar Turno" << endl;
        cout << "3. Registrar Asistencia" << endl;
        cout << "4. Salir" << endl;
    }while();

}

