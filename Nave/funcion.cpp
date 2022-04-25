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

void PintarLimites(){
    for(int i=2;i<118;i++){
        gotoxy(i,3);
        printf ("%c",205);
        gotoxy(i,28);
        printf ("%c",205);
    }
    for(int i=4;i<28;i++){
        gotoxy(1,i);
        printf ("%c",186);
        gotoxy(118,i);
        printf ("%c",186);
    }
    gotoxy(1,3);printf ("%c",201);
    gotoxy(1,28);printf ("%c",200);
    gotoxy(118,3);printf ("%c",187);
    gotoxy(118,28);printf ("%c",188);
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
        if (tecla==IZQUIERDA&&x>2) x--;
        if (tecla==DERECHA&&x<113) x++;
        if (tecla==ARRIBA&&y-1>3) y--;
        if (tecla==ABAJO&&y<25) y++;
        pintar();
}
