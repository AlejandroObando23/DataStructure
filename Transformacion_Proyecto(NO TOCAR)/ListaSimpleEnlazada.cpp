#include<iostream>
#include<string>
using namespace std;
struct Nodo
{
    string dato;
    Nodo *siguiente;
};
class ListaEnlazada
{
private:
    Nodo* cabeza;
public:
    ListaEnlazada():cabeza(NULL) {}

    ~ListaEnlazada()
    {
        while(cabeza != NULL)
        {
            Nodo* temp= cabeza;
            cabeza=cabeza->siguiente;
            delete temp;

        }

    }



    void insertAlFinal(const string& valor)
    {
        Nodo* nuevoNodo = new Nodo{valor, NULL};
        if(cabeza==NULL)
        {
            cabeza = nuevoNodo;
        }
        else
        {
            Nodo* actual =cabeza;
            while (actual ->siguiente != NULL)
            {
                actual=actual->siguiente;
            }
            actual->siguiente= nuevoNodo;


        }
    }

    bool buscarElemento(const string& valor)
    {
        Nodo* actual = cabeza;
        while (actual !=NULL)
        {
            if(actual->dato == valor)
            {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    void borrarElemento (const string& valor)
    {
        Nodo* actual =cabeza;
        Nodo* anterior = NULL;

        while(actual != NULL && actual->dato != valor)
        {
            anterior = actual;
            actual = actual->siguiente;
        }
        if(actual != NULL)
        {
            if(anterior != NULL)
            {
                anterior->siguiente = actual->siguiente;
            }
            else
            {
                cabeza=actual->siguiente;
            }
delete actual;
        }

    }

    void imprimirLista()
    {
        Nodo* actual = cabeza;
        while(actual != NULL)
        {
            cout<<actual->dato<<"";
            actual =actual ->siguiente;
        }
        cout<<endl;



    }
};

int mostrarMenu()
{
    int menu=0;
    cout<<"Bienvenidos al sistema"<<endl;
    cout<<"1. Insertar Elemento al final"<<endl;
    cout<<"2. Buacar elemento "<<endl;
    cout<<"3. Eliminar elemento"<<endl;
    cout<<"4. Mostrar elemento"<<endl;
    cout<<"Seleccionar una de las opciones disponibles"<<endl;
    cin>>menu;




    while(menu <1 || menu > 5)
    {
        cout<<"Seleccionar una de las opciones disponibles : "<<endl;
        cin>>menu;
    }

    return menu;

}
int main()
{
    char seguir;
    ListaEnlazada lista;

    do
    {
        int menu=mostrarMenu();
        int contador=0;
        string valor="";
        int buscar=0;
        switch(menu)
        {
        case 1:
            cout<<"Cuantos numeros desea ingresar "<<endl;
            cin>>contador;
            for(int i=0; i!=contador ; i++)
            {

                cout<<"El valor: "<<i<<endl;
                cin>>valor;
                lista.insertAlFinal(valor);




            }
             break;


        case 2:
            cout<<"Ingrese el elemento a buscar"<<endl;
            cin>>valor;
            lista.buscarElemento(valor);
            cout<<"El elemento fue encontrado y esta ubicado en el nodo "<<buscar<<endl;
            break;
        case 3:
            cout<<"Que elemento quiere eliminar"<<endl;
            cin>>valor;
            lista.borrarElemento (valor);
            break;
        case 5:
            lista.imprimirLista();
            cout<<endl;
            break;

        }
        cout<<"Desea continuar con la funcion "<<endl;
        cin>>seguir;


    }
    while(seguir =='s');

}

