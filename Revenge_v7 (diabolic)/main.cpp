#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "funciones.h"

using namespace std;

int main()
{


   //variables PANTALLA INICIAL (menu)
    int op1=-1, op2;
    //variables jugador y Orden de jugada
      string NombreJugador1, NombreJugador2, PrimerJugador, SegundoJugador;
    int DadoArranque1=0, DadoArranque2=0, x, i, v1[11], v2[11];

    //variables 12 caras
    int v12caras[2];


    //variables para calculo de turno
    int nrodado=-3, dadosElegidos=0, sumaSeleccionada=0, sumatotal1=0,sumatotal2=0, NumeroObjetivo, DadosStock1=6, DadosStock2=6;
    int turno,  dadoanterior [11]{};
    int CaraDadosElegidos[11], NumeroDadosElegidos[11];

   //Inicializador tiempo para dados (NO TOCA').
   srand(time(NULL));


    //PANTALLA INICIAL
    //(⌐■_■) carita facherita (◎﹏◎)

    while(op1!=0)

    //Funcion MENU
    {


        cout<<endl<<endl<<"REVENGE"<<endl<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"1 - JUGAR"<<endl;
        cout<<"2 - ESTADISTICAS"<<endl;
        cout<<"3 - CREDITOS"<<endl;
        cout<<"---------------------------------------------------------"<<endl<<endl;
        cout<<"0 - SALIR"<<endl;
        cin>>op1;
        switch(op1)
        {
        case 1:
            cout<< "Comienza el juego "<<endl<<endl<<endl;
            cout <<endl<<endl<< "Ingrese el nombre del Primer Jugador: " <<endl;
            cin >> NombreJugador1;
            cout << "Ingrese el nombre del Segundo Jugador: " << endl;
            cin >> NombreJugador2;

///Lanzar dado de "Quien comienza el juego", comienza el que saca el mayor. Repetir si hay empate.
    while (DadoArranque1 == DadoArranque2){
    cout <<endl<<endl<< NombreJugador1 << "  por favor, tire un dado: "<<endl;
    system("pause");
    lanzarDados(v1, 1);
    DadoArranque1 = v1[0];
    cout<<endl<<"***"<<DadoArranque1<<"***"<<endl;
    cout <<endl<<endl<< NombreJugador2 << "  por favor, tire un dado: " << endl;
    system("pause");
    lanzarDados(v2, 1);
    DadoArranque2 = v2[0];
    cout<<endl<<"***"<<DadoArranque2<<"***"<<endl;

//Segun dado mayor, organiza quien es el Primer jugador. !de jugador1 y jugador2
    }
    if (DadoArranque1 > DadoArranque2){
        PrimerJugador=NombreJugador1;
        SegundoJugador=NombreJugador2;

    }else{
        PrimerJugador=NombreJugador2;
        SegundoJugador=NombreJugador1;
    }
    cout<<endl<<endl<<"'''''''''''''El turno inicia con: "<<PrimerJugador<<"''''''''''''''''"<<endl<<endl;
    system("pause");

    cout<<endl<<"COMENZAMOS!"<<endl<<endl;

    //Dentro de este for (5 rondas del juego) deben:
//    *Tirar dados de 12 caras (y los suma)
//    *Tirar dadosstock
//    *Elegir dadosstock
//    *Calcular suma de valores de dados (OJO, tirada exitosa 10000pts blablabla)
//    *Calcular si suma exitosa
//    *Multiplicar suma de valores * cantidad de dados
//    *Sumar al total
//    *Restar dados si corresponde (y darselos al rival)
//    *Sumar dado (si tirada fallida) (OJO, solo si rival +1 dado)
//    *Pasar turno al SegundoJugador.

    for(x=1; x<=5; x++){

    //***************************************JUGADOR 1*******************************************************************

        cout<< endl<<"~ ~ ~ ~ ~ ~ ~ ~***Ronda Nro: "<<x<<"***~ ~ ~ ~ ~ ~ ~ ~"<<endl<<endl;
    ///Lanzar 2 dados de 12 caras.
        cout << PrimerJugador << ": Lance dos dados de 12 caras" << endl;
        lanzar12caras(v12caras, 2); //TODO: FUNCION DADO 12 CARAS
        ///Sumar caras de los dados de 12 caras "Numero objetivo" (entre 2 y 24)
        NumeroObjetivo = v12caras[0] + v12caras[1];
        cout<<endl<<"El valor objetivo es: "<<NumeroObjetivo<<endl<<endl;

    ///Lanzar "Dados stock (6 caras)" Jugador 1
        cout << PrimerJugador << ": Lance sus Dados Stock (cantidad de dados disponibles:"<<DadosStock1<<")"<<endl;
        system("pause");
        lanzarDados(v1, DadosStock1);

//*Elegir dadosstock primer jugador

    ///Seleccionar dados a sumar para igualar al objetivo
                cout << endl << "Elija el Nro de dado a Sumar (terminar suma con 0)" << endl << endl;
                dadosElegidos=0; //dadosElegidos: Suma de dados elegidos en el turno.
                sumaSeleccionada=0; //
                nrodado=-1;
                //While para elegir cantidad de dados a sumar, elige por numero de dados y busca valor de vector con "nrodado-1"



                seleccionarDados( DadosStock1, sumaSeleccionada,NumeroObjetivo, v1, CaraDadosElegidos, NumeroDadosElegidos, dadosElegidos );


                cout<< endl << "La suma de los dados Elegidos es: "<<sumaSeleccionada<<endl;
                for(i=0;i<dadosElegidos;i++){
                        if(dadosElegidos!=0){
                    cout<<"  Dado "<<NumeroDadosElegidos[i]<<": "<<CaraDadosElegidos[i]<<"  ";
                }}



                if(NumeroObjetivo==sumaSeleccionada)
                {
                    cout<< endl <<"*** TIRADA EXITOSA ***"<<endl;
                    cout<< endl<< "Numero objetivo: "<< NumeroObjetivo;

                    turno=sumaSeleccionada*dadosElegidos;
                    cout<< endl<< "En este turno hiciste "<<sumaSeleccionada<<"*"<<dadosElegidos<<" = "<<turno<<" puntos."<<endl;
                    sumatotal1+=turno;
                    if(DadosStock1==0){
                        cout<<"FELICIDADES WACHIN, GANASTE AL RIVAL"<<endl;
                        sumatotal1+=10000;
                        break;
                    }

                    cout<<PrimerJugador<<" lleva "<<sumatotal1<<" puntos acumulados."<<endl<<endl;
                    DadosStock1-=dadosElegidos;
                    DadosStock2+=dadosElegidos;

                    cout<<endl<<"Se envian "<<dadosElegidos<<" dados a "<<SegundoJugador<<endl;

                    cout<<PrimerJugador<<", te quedan "<<DadosStock1<<" dados."<<endl;
                    cout<<SegundoJugador<<", te quedan "<<DadosStock2<<" dados."<<endl;
                }
                else
                {
                    if(DadosStock2>1)
                    {
                        DadosStock1+=1;
                        DadosStock2-=1;
                    cout<< endl<<"***No sumas puntos, y ganas un dado del rival :c ***"<<endl;
                    cout<<PrimerJugador<<", te quedan "<<DadosStock1<<" dados."<<endl;
                    cout<<SegundoJugador<<", te quedan "<<DadosStock2<<" dados."<<endl;
                    }
                    else{
                    cout<<endl<<"***No sumas puntos, (pete)***"<<endl;
                    }
                }


    //***************************************JUGADOR 2*******************************************************************
 cout<< endl<<"~ ~ ~ ~ ~ ~ ~ ~***Ronda Nro: "<<x<<"***~ ~ ~ ~ ~ ~ ~ ~"<<endl<<endl;
    ///Lanzar 2 dados de 12 caras.
        cout << SegundoJugador << ": Lance dos dados de 12 caras" << endl;
        lanzar12caras(v12caras, 2); //TODO: FUNCION DADO 12 CARAS
        ///Sumar caras de los dados de 12 caras "Numero objetivo" (entre 2 y 24)
        NumeroObjetivo = v12caras[0] + v12caras[1];
        cout<<endl<<"El valor objetivo es: "<<NumeroObjetivo<<endl<<endl;

    ///Lanzar "Dados stock (6 caras)" Jugador 1
        cout << SegundoJugador << ": Lance sus Dados Stock (cantidad de dados disponibles:"<<DadosStock2<<")"<<endl;
        system("pause");
        lanzarDados(v1, DadosStock2);

//*Elegir dadosstock primer jugador

    ///Seleccionar dados a sumar para igualar al objetivo
                cout << endl << "Elija el Nro de dado a Sumar (terminar suma con 0)" << endl << endl;
                dadosElegidos=0; //dadosElegidos: Suma de dados elegidos en el turno.
                sumaSeleccionada=0; //
                nrodado=-1;
                //While para elegir cantidad de dados a sumar, elige por numero de dados y busca valor de vector con "nrodado-1"



                seleccionarDados( DadosStock2, sumaSeleccionada,NumeroObjetivo, v1, CaraDadosElegidos, NumeroDadosElegidos, dadosElegidos );


                cout<< endl << "La suma de los dados Elegidos es: "<<sumaSeleccionada<<endl;
                for(i=0;i<dadosElegidos;i++){
                    cout<<"  Dado "<<NumeroDadosElegidos[i]<<": "<<CaraDadosElegidos[i]<<"   ";
                }



                if(NumeroObjetivo==sumaSeleccionada)
                {
                    cout<< endl <<"*** TIRADA EXITOSA ***"<<endl;
                    cout<< endl<< "Numero objetivo: "<< NumeroObjetivo;

                    turno=sumaSeleccionada*dadosElegidos;
                    cout<< endl<< "En este turno hiciste "<<sumaSeleccionada<<"*"<<dadosElegidos<<" = "<<turno<<" puntos."<<endl;
                    sumatotal2+=turno;
                    if(DadosStock2==0){
                        cout<<"FELICIDADES WACHIN, GANASTE AL RIVAL"<<endl;
                        sumatotal2+=10000;
                        break;
                    }

                    cout<<SegundoJugador<<" lleva "<<sumatotal2<<" puntos acumulados."<<endl<<endl;
                    DadosStock2-=dadosElegidos;
                    DadosStock1+=dadosElegidos;

                     cout<<endl<<"Se envian "<<dadosElegidos<<" dados a "<<PrimerJugador<<endl;

                    cout<<PrimerJugador<<", te quedan "<<DadosStock1<<" dados."<<endl;
                    cout<<SegundoJugador<<", te quedan "<<DadosStock2<<" dados."<<endl;
                }
                else
                {
                    if(DadosStock1>1)
                    {
                        DadosStock2+=1;
                        DadosStock1-=1;
                    cout<<endl<<"***No sumas puntos, y ganas un dado del rival :c ***"<<endl;
                    cout<<PrimerJugador<<", te quedan "<<DadosStock1<<" dados."<<endl;
                    cout<<SegundoJugador<<", te quedan "<<DadosStock2<<" dados."<<endl;
                    }
                    else{
                    cout<<endl<<"***No sumas puntos, (pete)***"<<endl;
                    }
                }}

            break;
        case 2:
            cout<<PrimerJugador<<"-- Puntaje total: "<<sumatotal1<<endl;
            cout<<SegundoJugador<<"-- Puntaje total: "<<sumatotal2<<endl;

            break;
        case 3:
            cout<<"*************************"<<endl;
            cout<<"Grupo 15: <<<Inserte nombre cheto>>>"<<endl;
            cout<<"25448 - Castro, Martina *The Boss*  "<<endl;
            cout<<"25441 - Calicanton, Sebastian "<<endl;
            cout<<"25630 - Villalba, Mauricio "<<endl;
            cout<<"25637 - Vilaplana, Erik "<<endl;
            cout<<"*************************"<<endl;
            break;
        case 0:
            cout<<" ESTAS SEGURO QUE DESEAS SALIR????"<<endl;
            cout<<"1 - SI, SALIR"<<endl<<"2 - NO, QUEDARME EN ESTE GRANDIOSO JUEGO"<<endl;
            cin>>op2;
            if(op2==1)
            {
                op1=0;
            }else{
            op1=1;}

    break;
        }
    }
        //FIN FUNCION MENU







    }

    //Bitacora de REVENGE. 16/11/2021 00:21: El juego es funcional para 1 jugador hasta suma de puntos y quita de dados.
    //16/11/2021 17:45 ROBA DADOS SIEMPRE, FIX
    //16/11/2021 23:25 ya no roba dados. Funciona para 2 jugadores full, muestra estadistica.
    //
    //17/11/2021 10:17: Surgen cosas al leer consigna:
    //18/11/2021 00:09: Juego funcional al 100%, Bugs conocidos: Al sumar mal y poner 0, muestra todos los dados usados, incluso el 0,
    //                  y muestra en cout darle esa cantidad al rival (no lo hace realmente).






////Esto es:
//Si es una tirada exitosa indicarlo además de mostrar cuál era la suma objetivo, LO HACE CASI IGUAL // FIXED
// mostrar las caras de los dados elegidos MUESTRA DURANTE AL TIRAR, PERO NO AL TENER TIRADA EXITOSA
//  y la suma total de puntos e indicar cuántos dados se le envían al contrincante. LO HACE CASI IGUAL
//Si no es una tirada exitosa indicarlo además de mostrar cuántos dados recibe de su contrincante (puede ser uno o cero). LO HACE PERO NO LO DICE
//También debe contemplar que el jugador haya logrado una tirada exitosa que además finalice el juego. Entonces debe indicarlo particularmente y terminar la partida. NO LO HACE
//
////
//
//
////     Al ir seleccionando cada dado, debe automáticamente sumarlos y compararlos con la suma objetivo. NO LO HACE
// En el momento que ambas sumas sean iguales, finaliza la ronda.  AHORA SIEMPRE SE TERMINA LA SELECCION con 0.
//El juego no contemplará la posibilidad de que el usuario se equivoque. NO CONTEMPLA SUMA, SI CONTEMPLA DADOS NO VALIDOS O REPETIDOS
// Dado seleccionado es un dado sumado. Si por alguna razón el jugador no puede lograr una suma que le otorgue una tirada exitosa.
//  Puede ingresar un número de dado 0 para que finalice una ronda como no exitosa. ETO TA OK
//
////
////
//
//


    // Tareitas para igualar consigna:
    //                                     *Espacios en los puntajes de turno. Aun faltan
    //                                     *Turno de jugador 1 y 2 separados y sin funciones, ver de achicar codigo.
    //                                     *Agregar bonus de 10k y fin de juego.
    //                                     *Agregar cout cuando no sumas puntos//AGREGADO//FALTA FULL VERTIFICATION
    //                                     *Sumaobjetivox debe llamarse NumeroObjetivox. LISTO
    //                                     *cantx debe llamarse DadosStockx. LISTO
    //                                     *contadoreEleigo debe llamarse DadosElegidos. LISTO
    //                                     *sumaturno debe llamarse SumaSeleccionada. LISTO
    //                                     *la jefa me esplota, bring me sindicate. ME DEBES PLUSVALOR, Y DEL BUENO.
    // Convertir while de ingreso de dados a un for.
    // Mecanismo de ingreso distinto de dados (Guardar y borrar).

    /// Borramos segunda funcion de lanzarDados2 y solo usamos 1 (PARA DADO DE ARRANQUE).
