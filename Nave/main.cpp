#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "funcion.h"
#include "Clases.h"

int main(){
    OcultarCursor();
    aeronave n(50,30);
    n.pintar();
    bool gameover=false;
    while(!gameover){
        n.mover();
    }

    return 0;
}
