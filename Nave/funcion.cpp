#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "funcion.h"
#include "Clases.h"

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

//Funciones globales

void gotoxy(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void OcultarCursor(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 20;
    cci.bVisible = false;
    SetConsoleCursorInfo(hCon, &cci);
}


//Metodos de clases

void aeronave::pintar(){
    gotoxy(x,y);
    printf ("  %c",30);
    gotoxy(x,y+1);
    printf (" %c%c%c",40,207,41);
    gotoxy(x,y+2);
    printf ("%c%c %c%c",30,190,190,30);
}

void aeronave::borrar(){
    gotoxy(x,y);
    printf("     ");
    gotoxy(x,y+1);
    printf("     ");
    gotoxy(x,y+2);
    printf("     ");
}

void aeronave::mover(){
        char tecla=getch();
        borrar();
        if (tecla==IZQUIERDA) x--;
        if (tecla==DERECHA) x++;
        if (tecla==ARRIBA) y--;
        if (tecla==ABAJO) y++;
        pintar();
}
