#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "funcion.h"
#include "Clases.h"

int main(){
    OcultarCursor();
    PintarLimites();
    aeronave n(50,25);
    n.pintar();
    bool gameover=false;
    while(!gameover){
        n.mover();
    }

    return 0;
}
