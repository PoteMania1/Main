#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "funciones.h"

using namespace std;

//funcion de lanzar dados para jugador (usa v1[])
void lanzarDados(int v1[], int cant){
    int nrodado1=0;

    for(int i=0; i<cant; i++){
        v1[i] = 1 + rand() % 6; //rand devuelve un numero aleatorio grande, me quedo con el resto, el resto va a estar entre el 0 y el 5. Entonces le sumamos 1 para que entre 1 y 6.
    nrodado1++;
    cout<<"Dado N"<<nrodado1<<": "<<v1[i]<<endl; //cout de control, remover en version final

    }
}


    //funcion para lanzar 2 dados de 12 caras (deberia funcionar para ambos jugadores)
    void lanzar12caras(int v12caras[], int cant){
    int nrodado1=0;
    for(int i=0; i<cant; i++){
        v12caras[i] = 1 + rand() % 12; //rand devuelve un numero aleatorio grande, me quedo con el resto, el resto va a estar entre el 0 y el 5. Entonces le sumamos 1 para que entre 1 y 6.
    nrodado1++;
    cout<<"Dado N "<<nrodado1<<": "<<v12caras[i]<<endl;

    }}

int Dadorepetido (int nrodado, int dadoanterior[], int contadorelegido, int cant1){
    int x,Band=0;

    if(nrodado > cant1){
       Band = 1;
       }
       else{
        for(x=0; x<contadorelegido; x++){
                if(nrodado==dadoanterior[x]){
                    Band=1;}
                }

       }
    return Band;
    }


void seleccionarDados(int cantidadDados, int &sumaSeleccionada, int NumeroObjetivo, int v1[], int CaraDadosElegidos[], int NumeroDadosElegidos[] , int &dadosElegidos){
     int  nrodado=-1;


//Si es una tirada exitosa indicarlo además de mostrar cuál era la suma objetivo,
// mostrar las caras de los dados elegidos y la suma total de puntos
//  e indicar cuántos dados se le envían al contrincante.




            while(sumaSeleccionada!=NumeroObjetivo&&nrodado!=0){

                    cin>>nrodado;

                    if(dadosElegidos<cantidadDados){
                        if(nrodado<=cantidadDados){
                            if(nrodado!=0){
                            NumeroDadosElegidos[dadosElegidos]=nrodado;
                            CaraDadosElegidos[dadosElegidos]=v1[nrodado-1];
                            dadosElegidos++;

                            sumaSeleccionada+=v1[nrodado-1];
                            cout<<"**** dados eleg "<<dadosElegidos<<"***"<<endl;
                            cout<<"****Suma turno "<<sumaSeleccionada<<"***"<<endl;
                            cout<<"****numero obj"<<NumeroObjetivo<<"***"<<endl;
                            }
                            }
                            else{
                                cout<< "fua escubi la re vivis, no tenes tantos dados"<< endl;
                            }
                    }else{
                    cout<<"Te pasaste de dados, pone 0 y termina el turno."<<endl;
                    }

            }
}





