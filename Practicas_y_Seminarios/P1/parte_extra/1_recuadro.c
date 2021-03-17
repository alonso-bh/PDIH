/*****************************************************************************/
// PERIFÉRICOS Y DISPOSITIVOS DE INTERFAZ HUMANA
// GRADO EN INGENIERÍA INFORMÁTICA
//
// ALONSO BUENO HERRERO, BARTOLOMÉ ZAMBRANA PÉREZ
//
// CURSO 2020/21
// Práctica 1. E/S con interrupciones en lenguaje C
//
/*
    Programa: 1_recuadro.c recoge la primera actividad extra (para subir nota)
    
*/
/*****************************************************************************/

#include <stdio.h>
#include <dos.h>
#include "P1.h"   // adaptar la ruta de la biblioteca para que este include no dé errores



void recuadro(int x1, int y1, int x2, int y2, int color_fondo, int color_fuente){
    int i,j;
    //Establecemos los colores.
    textcolor(color_fuente);
    textbackground(color_fondo);

    
    for(i = 0; i <= (x2 - x1); i++){
        //Horizontal Superior.
        gotoxy(x1 + i, y1);
        cputchar('|');

        //Horizontal Inferior.
        gotoxy(x2 - i , y2);
        cputchar('|');
    }

    for(j = 0; j <= (y2 - y1); j++){
        //Linea izquierda.
        gotoxy(x1, y1 + j);
        cputchar('-');
        
        //Linea derecha
        gotoxy(x2, y2 - j);
        cputchar('-');
    }
}

int main(){
    clrscr();
    recuadro(3,3,10,10,2,1);
    printf("\n\n\n");
}