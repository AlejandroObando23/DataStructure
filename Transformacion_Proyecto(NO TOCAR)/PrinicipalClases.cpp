#include <iostream>
#include <conio.h>
#include "Clase_S_PersonaTurno.h"
#include "ValidarPin.h"

#define ANSI_BACKGROUND_BLUE "\033[44m"
#define ANSI_BACKGROUND_RESET "\033[0m"

int escogerOpcion();
void mostrarMenuPrincipal(int opcionActual);
    ClasePersona ps;
    ClaseTurno to;
    Turno* circular;
int main()

{
    bool salir = false;
    ps.cargar_personas();
    to.cargar_turno();
    circular=to.cabeza;


    int opcion;

    do
    {
        opcion = escogerOpcion();

        switch(opcion)
        {
        case 1:
            cout<<"-----Agregar Turno----"<<endl;
            //   pedirPin();
            //   agregarTurno();
            break;
        case 2:
            cout<<"-----Modificar Turno----"<<endl;
            pedirPin();
            break;
        case 4:
            ps.mostar_Personas();
            break;
        case 5:
            to.mostar_Turnos();
            break;
        case 6:
            circular=circular->sig;

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

void mostrarMenuPrincipal(int opcionActual)
{
    cout << "\t\t=== Bienvenido al sistema de Turnos ===" << endl;
    to.imprimirInfoTurno(circular);
    cout << "\t\t=== Bienvenido al sistema de Turnos ===" << endl;
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
            cout << "\t1. Agregar Turno" << endl;
            break;
        case 2:
            cout << "\t2. Modificar Turno" << endl;
            break;
        case 3:
            cout << "\t3. Registrar Asistencia" << endl;
            break;
        case 4:
            cout << "\t4. Ver lista de Personas" << endl;
            break;
        case 5:
            cout << "\t5. Ver lista de Turnos" << endl;
            break;
        case 6:
            cout << "\t6. Siguiente Turno"<< endl;
            break;
        case 7:
            cout << "\t7. Salir" << endl;
            break;
        }
    }
    printf("%s",ANSI_BACKGROUND_RESET);
    cout << "\t===========================" << endl;
}

