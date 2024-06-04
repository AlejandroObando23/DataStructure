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

