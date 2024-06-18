#include<iostream>

using namespace std;

void pedirPin(){
int pinIngresado;
const int pinCorrecto = 1234;
  do{
    cout<<"\nIngrese su PIN de 4 digitos "<<endl;
    cout<<"PIN: ";
    cin>>pinIngresado;

    if(cin.fail() || (pinIngresado < 1000 || pinIngresado > 9999)){
      cin.clear();
      cin.ignore();
      cout<<"Error: El PIN debe ser un numero de 4 digitos."<<endl;
    }else{
      if(pinIngresado == pinCorrecto){
        cout<<"Pin Correcto"<<endl;
        cout<<"Acceso concedido....";
         getch();
      }else{
        cout<<"Error: PIN incorrecto."<<endl;
      }
    }
  }while(cin.fail() || (pinIngresado < 1000 || pinIngresado > 9999) || pinIngresado != pinCorrecto   );
}

