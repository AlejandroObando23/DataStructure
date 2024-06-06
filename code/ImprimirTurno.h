#include <iostream>

using namespace std;

template <typename T>
void imprimirInfoTurno(T* lista){

    if(lista != nullptr){
    cout << "\n\t======================================" << endl;
    cout << "\t== Turno Actual ==" << endl;
    cout << "\tHorario: " << lista->horaInicio << ":00 - " << lista->horaFinal << ":00 " << endl;
    cout << "\tEncargado: " << lista->doctor.nombre << " " << lista->doctor.apellido << endl;
    cout <<  "\tID: " << lista->doctor.id << endl;
    cout << "\t======================================\n" << endl;
    }
    else{
        cout << "\nLa lista esta vacia, listo para agregar turnos\n" << endl;
    }
}
