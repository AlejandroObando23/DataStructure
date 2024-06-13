#include <iostream>
#include <ctime>

using namespace std;

bool registrarAsistencia(int op){
    time_t now = time(0);
    tm* time = localtime(&now);

    cout << time->tm_mday << time->tm_mon << time->tm_year;

    string id, nombre, apellido, asistencia;
    ofstream nuevoRegistro;

    cout << "Ingrese su id para registrar: ";
    cin >> id;

    encontrarDoctor(id, nombre, apellido);

    switch(op){
        case 1:
            asistencia = "Entrada:";
            break;
        case 2:
            asistencia = "Salida:"
            break;
    }

    nuevoRegistro.open("RegistroAsistencia.txt", ios::app);
    if (nuevoRegistro.fail()) {
        cout << "No se pudo abrir el archivo correctamente" << endl;
        exit(1);
    }

    nuevoRegistro << "\n" << fechaActual << "\t" << nombre << "\t" << apellido << "\t" << asistencia << "\t" << horaRegistro;
    cout<<"\n-----Se ha registrado la asistencia correctamente-------\n";
    nuevoRegistro.close();

}
