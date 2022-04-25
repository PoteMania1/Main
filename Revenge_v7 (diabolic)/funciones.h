#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//funcion de dados para primerjugador (usa v1[])
void lanzarDados(int v1[], int cant);

 //funcion para lanzar 2 dados de 12 caras (deberia funcionar para ambos jugadores)
void lanzar12caras(int v12caras[], int cant);

//Funcion para mostrar "Reigresar Numero de Dado" si ingreso numero repetido o mayor a la cantidad de dados.
int Dadorepetido (int nrodado, int dadoanterior[], int contadorelegido, int cant1);

//Funcion para elegir dados durante el turno.  ¯\_(ツ)_/¯
void seleccionarDados(int cantidadDados, int &sumaSeleccionada, int NumeroObjetivo, int v1[], int CaraDadosElegidos[], int NumeroDadosElegidos[] , int &dadosElegidos);


#endif // FUNCIONES_H_INCLUDED
