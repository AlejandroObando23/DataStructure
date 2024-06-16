#include <iostream>
#include <string.h>
using namespace std;

struct Persona{
    string id;
    string nombre;
    string apellido;
    Persona* sig;
};

struct Turno{
    int horaInicio;
    int horaFinal;
    Persona paciente;
    Persona doctor;
    Turno* sig;
};
