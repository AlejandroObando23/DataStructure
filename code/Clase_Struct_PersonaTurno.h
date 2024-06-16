
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


};

struct Turno
{
    int horaInicio;
    int horaFinal;
    Persona doctor;
    Persona paciente;
    Turno* sig;
};
class ClaseTurno
{
};

