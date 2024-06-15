#include<iostream>
using namespace std;

const int max_size=100;

struct ListaEstatica
{
    int datos[max_size];
    int siguiente;
};
void iniciarLista(ListaEstatica &lista)
{
    lista.siguiente =0;
}

void insertarElemento(ListaEstatica &lista, int nuevoElemento)
{
    if(lista.siguiente < max_size)
    {
        lista.datos[lista.siguiente] = nuevoElemento;
        lista.siguiente++;
    }
    else
    {
        cout<<"Error: la lista esta llena "<<endl;
    }

}
void eliminar(ListaEstatica &lista, int elemento)
{
    int pos= -1;
    for (int i=0; i<lista.siguiente; i++)
    {
        if(lista.datos[i]==elemento)
        {
            pos=1;
            break;
        }
    }
    if(pos != -1)
    {
        for(int i=pos; i< lista.siguiente -1; i++)
        {
            lista.datos[i]= lista.datos[i+1];
        }
        lista.siguiente--;

    }
    else
    {
        cout<<"No se puede hacer la operaciones"<<endl;;
    }

}
void imprimirLista(const ListaEstatica &lista)
{
    for (int i=0; i<lista.siguiente; i++)
    {
        cout<<lista.datos[i];

    }
}

void vaciarLista(ListaEstatica &lista)
{
    lista.siguiente=0;
}

int buscarElemento(const ListaEstatica &lista,int &elemento)
{
    for(int i=0; i< lista.siguiente; i++)
    {
        if(lista.datos[i]== elemento)
        {

            return i;
        }

    }

    return -1;

}

int mostrarMenu()
{
    int menu=0;
    cout<<"Bienvenidos al sistema"<<endl;
    cout<<"1. Insertar Elementos en la lista"<<endl;
    cout<<"2. Buacar elemento "<<endl;
    cout<<"3. Eliminar elemento"<<endl;
    cout<<"4. Vaciar elemento"<<endl;
    cout<<"5. Mostrar elemento"<<endl;
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
    ListaEstatica lista;
    iniciarLista(lista);
    do
    {
        int menu=mostrarMenu();
        int contador=0;
        int valor=0;
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
                insertarElemento(lista, valor);



            }
             break;


        case 2:
            cout<<"Ingrese el elemento a buscar"<<endl;
            cin>>valor;
            buscar=buscarElemento(lista,valor);
            cout<<"El elemento fue encontrado y esta ubicado en el nodo "<<buscar<<endl;
            break;
        case 3:
            cout<<"Que elemento quiere eliminar"<<endl;
            cin>>valor;
            eliminar(lista, valor);
            break;
        case 4:
            vaciarLista(lista);
            break;
        case 5:
            imprimirLista(lista);
            cout<<endl;
            break;

        }
        cout<<"Desea continuar con la funcion "<<endl;
        cin>>seguir;


    }
    while(seguir =='s');

}
