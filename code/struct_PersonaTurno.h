#include <iostream>
#include <string.h>
using namespace std;
template <typename T1, typename T2, typename T3>
struct Persona{
    T1 id;
    T2 nombre;
    T3 apellido;
    Persona* sig;
};
template <typename T1,typename T2>
struct Turno{
    T1 horaInicio;
    T2 horaFinal;
    Persona<string,string,string> doctor;
    Turno* sig;
};
