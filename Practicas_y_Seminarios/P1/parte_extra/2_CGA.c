/*****************************************************************************/
// PERIFÉRICOS Y DISPOSITIVOS DE INTERFAZ HUMANA
// GRADO EN INGENIERÍA INFORMÁTICA
//
// ALONSO BUENO HERRERO, BARTOLOMÉ ZAMBRANA PÉREZ
//
// CURSO 2020/21
// Práctica 1. E/S con interrupciones en lenguaje C
//
/**
 * Implementar en lenguaje C un programa 
 * que establezca modo gráfico CGA para 
 * crear dibujos sencillos en pantalla.
 * 
*/
/*****************************************************************************/



#include <dos.h>
#include "P1.h"  // adaptar la ruta de la biblioteca para que este include no dé errores


void pixel(int x, int y, unsigned char color){
    union REGS inregs, outregs;

    inregs.x.cx = x;
    inregs.x.dx = y;
    inregs.h.al = color;
    inregs.h.ah = 0X0C;
    int86(0x10, &inregs, &outregs);
}

int main(){
    int i;
    setvideomode(4); //Modo gráfico.

    pixel(10,40,0);
    pixel(10,50,1);
    pixel(15,60,2);
    pixel(20,70,3);

    //Dibujamos un triángulo rectángulo
    for(i = 0; i < 45 ; i++){
        //Base
        pixel(10+i,100, 3);
        //Linea izquierda,
        pixel(10+i,100+i,2);
        //Línea derecha
        pixel(55,100+i,1);
    }

    mi_pausa();

    setvideomode(3); //Modo texto;
    return 0;
}