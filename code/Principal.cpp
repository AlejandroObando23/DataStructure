#include <iostream>
#include <string.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>
#include "struct_PersonaTurno.h"
#include "Cargar_personas.h"
#include "Cargar_turno.h"
#include "ImprimirTurno.h"
#include "ValidarPin.h"

#define ANSI_BACKGROUND_BLUE "\033[44m"
#define ANSI_BACKGROUND_RESET "\033[0m"

using namespace std;

Persona* inicioPersona=nullptr;
Turno* inicioTurno=nullptr;

Turno* aux;

int validarNumero(char numero[]){
    for(int i = 0; i <strlen(numero);i++){
        if(!isdigit(numero[i])){
            cout << "Ingrese un valor entero válido" << endl;
            return 0;
        }
    }
    return 1;
}

void mostrarMenuPrincipal(int opcionActual)
{
    cout << "\t\t=== Bienvenido al sistema de Turnos ===" << endl;
    if(aux != nullptr)
    {
        imprimirInfoTurno<Turno>(aux);
    }
    else
    {
        cout << "La lista se encuentra vacia, listo para agregar turnos" << endl;
    }

    cout << "\n\tSeleccione una opcion:\n" << endl;
    cout << "\t===========================" << endl;
    for(int i=1; i<=7; i++)
    {
        if(i==opcionActual)
        {
            printf("%s",ANSI_BACKGROUND_BLUE);
        }
        else
        {
            printf("%s",ANSI_BACKGROUND_RESET);
        }

        switch(i)
        {
        case 1:
            cout << "\t1. Administrador" << endl;
            break;
        case 2:
            cout << "\t2. Registrar Asistencia" << endl;
            break;
        case 3:
            cout << "\t3. Siguiente Turno" << endl;
            break;
        case 4:
            cout << "\t4. Asignar Paciente" << endl;
            break;
        case 5:
            cout << "\t5. Ver Turnos" << endl;
            break;
        case 6:
            cout << "\t6. Ver Doctores"<< endl;
            break;
        case 7:
            cout << "\t7. Salir" << endl;
            break;
        }
    }
    printf("%s",ANSI_BACKGROUND_RESET);
    cout << "\t===========================" << endl;
}

int escogerOpcion()
{
    int opcionActual=1;
    while(1)
    {
        system("cls");
        mostrarMenuPrincipal(opcionActual);
        char tecla =_getch();
        switch(tecla)
        {
        case 72:
            opcionActual=(opcionActual>1)?opcionActual-1:7;
            break;
        case 80:
            opcionActual=opcionActual<7?opcionActual+1:1;
            break;
        case 13:
            system("cls");
            switch(opcionActual)
            {
            case 1:
                return 1;
                break;
            case 2:
                return 2;
                break;
            case 3:
                return 3;
                break;
            case 4:
                return 4;
                break;
            case 5:
                return 5;
                break;
            case 6:
                return 6;
                break;
            case 7:
                return 7;
                break;
            };
            break;
        }
    }
}

void mostar_Turnos(Turno* aux)
{

    cout<<"\t-------- LISTA DE TURNOS REGISTRADOS --------"<<endl;
    cout<<"\t==============================================================="<<endl;
    cout<<"\t| HORA INICIO | HORA LLEGADA |"<<endl;
    cout<<"\t==============================================================="<<endl;

    Turno* turnoEncontrado = aux;

    do{
        if (turnoEncontrado != NULL)
        {
            cout << "\n\t    " << turnoEncontrado->horaInicio<< ":00" <<"\t"<< turnoEncontrado->horaFinal << ":00"<< "\t"<< endl;
        }
        turnoEncontrado = turnoEncontrado->sig;

    }while (turnoEncontrado != aux);
    cout << "\n";
    system("pause");
}

void mostar_Personas(Persona* aux)
{

    cout<<"\t------LISTA DE Personas REGISTRADOS--------"<<endl;
    cout<<"\t==============================================================="<<endl;
    cout<<"\t|   ID   |   NOMBRE   |   Apellido |"<<endl;
    cout<<"\t==============================================================="<<endl;

    Persona* alumnoEncontrado = aux;
    while (alumnoEncontrado != NULL)
    {
        if (alumnoEncontrado != NULL)
        {
            cout << "\n\t" << alumnoEncontrado->id << "\t" << alumnoEncontrado->nombre <<"\t"<< alumnoEncontrado->apellido<< "\t"<< endl;
        }
        alumnoEncontrado = alumnoEncontrado->sig;
    }
    cout << "\n";
    system("pause");
}

void encontrarDoctor(string idDoctor, string& nombre, string& apellido)
{
    Persona* doctor = inicioPersona;
    while (doctor != nullptr)
    {
        if (doctor->id == idDoctor)
        {
            nombre = doctor->nombre;
            apellido = doctor->apellido;
            return;
        }
        doctor = doctor->sig;
    }
    nombre = "";
    apellido = "";
    cout << "Error: El doctor con ID " << idDoctor << " no ha sido registrado." << endl;
}

void agregarTurno()
{
    string idDoctor;
    string nombre, apellido;

    cout << "Ingrese el ID del Doctor: ";
    cin >> idDoctor;

    encontrarDoctor(idDoctor, nombre, apellido);
    if (!nombre.empty() && !apellido.empty())
    {
        cout << "\t------------------------------------" << endl;
        cout << "\t|    DATOS PERSONALES DEL DOCTOR   |" << endl;
        cout << "\t------------------------------------" << endl;
        cout << endl;
        cout << "ID registrado : " << idDoctor << endl;
        cout << "NOMBRE        : " << nombre << endl;
        cout << "APELLIDO      : " << apellido << endl;
        cout << endl;

        // Mostrar los turnos disponibles
        cout << "Turnos disponibles:" << endl;


        // Solicitar al usuario que seleccione un turno
        int opcionTurno;
        cout << "Seleccione un turno: ";
        cin >> opcionTurno;

        // Buscar el turno seleccionado
        Turno* turnoSeleccionado = inicioTurno;
        for (int i = 1; i < opcionTurno && turnoSeleccionado != nullptr; ++i)
        {
            turnoSeleccionado = turnoSeleccionado->sig;
        }

        // Verificar si se encontró el turno
        if (turnoSeleccionado != nullptr)
        {
            // Mostrar los detalles del turno seleccionado
            cout << "\t------------------------------------" << endl;
            cout << "\t|        DETALLES DEL TURNO        |" << endl;
            cout << "\t------------------------------------" << endl;
            cout << "Hora de inicio: " << turnoSeleccionado->horaInicio << ":00" << endl;
            cout << "Hora final    : " << turnoSeleccionado->horaFinal << ":00" << endl;
        }
        else
        {
            cout << "Opción de turno inválida." << endl;
        }
    }
    else
    {
        cout << "No se encontró ningún doctor con ese ID." << endl;
    }
    system("pause");
}

void registrarAsistencia(int op){
    time_t now = time(0);
    tm* time = localtime(&now);
    string mes;
    string id, nombre, apellido, asistencia;
    ofstream nuevoRegistro;

    cout << "Ingrese su id para registrar: ";
    cin >> id;

    encontrarDoctor(id, nombre, apellido);
    if(nombre != "" && apellido != ""){
        switch(op){
            case 1:
                asistencia = "Entrada:";
                break;
            case 2:
                asistencia = "Salida:";
                break;
        }

        nuevoRegistro.open("RegistroAsistencia.txt", ios::app);
        if (nuevoRegistro.fail()) {
            cout << "No se pudo abrir el archivo correctamente" << endl;
            exit(1);
        }

        nuevoRegistro << "\n" << time->tm_mday << "/" << time->tm_mon+1 <<"/" << 1900+time->tm_year << "\t" << nombre << "\t" << apellido << "\t" << asistencia << "\t" << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec;
        cout<<"\n-----Se ha registrado la asistencia correctamente-------\n";
        nuevoRegistro.close();
    }else{
        cout << "\t================================" << endl;
        cout << "\t|No se encontró el id ingresado|" << endl;
        cout << "\t================================" << endl;
    }

    system("pause");
}

int menuAdmin(){
    int n, N;
    char validarN[2];
    cout << "\t============================" << endl;
    cout << "\t1.- Asignar Doctor al Turno" << endl;
    cout << "\t2.- Modificar Turno" << endl;
    cout << "\t3.- Regresar" << endl;
    cout << "\t============================" << endl;
    do{
        cin >> validarN;
        N = validarNumero(validarN);
        if(N == 1){
            n = atoi(validarN);
        }
    }while(N == 0);

    return n;
}

int menuAsistencia(){
    int n, N;
    char validarN[2];
    cout << "\t============================" << endl;
    cout << "\t1.- Registrar Entrada" << endl;
    cout << "\t2.- Registrar Salida" << endl;
    cout << "\t3.- Regresar" << endl;
    cout << "\t============================" << endl;
    do{
        cin >> validarN;
        N = validarNumero(validarN);
        if(N == 1){
            n = atoi(validarN);
        }
    }while(N == 0);
    return n;
}

int main()
{

    bool salir = false;
    int opcion, op, op1;

    cargar_personas(inicioPersona);
    cargar_turno(inicioTurno);
    aux = inicioTurno;
    do
    {
        opcion = escogerOpcion();

        switch(opcion)
        {
        case 1:
            cout<<"\t-----Administrador----"<<endl;
            pedirPin();
            op = menuAdmin();
            switch(op){
                case 1:
                    agregarTurno();
                    break;
                case 2:
                    break;
                case 3:
                    break;
            }
            break;
        case 2:
            cout<<"\t-----Registrar Asistencia----"<<endl;
            op1 = menuAsistencia();
            switch(op1){
                case 1:
                    registrarAsistencia(1);
                    break;
                case 2:
                    registrarAsistencia(2);
                    break;
                case 3:
                    break;
            }
            break;
        case 3:
            aux = aux->sig;
            break;
        case 4:
            cout<<"\t-----Asignar Paciente----"<<endl;
            break;
        case 5:
            mostar_Turnos(inicioTurno);
            break;
        case 6:
            mostar_Personas(inicioPersona);
            break;
        case 7:
            cout<<"Saliendo del programa...";
            salir = true;
            break;
        }
    }
    while(!salir);

    return 0;
}



