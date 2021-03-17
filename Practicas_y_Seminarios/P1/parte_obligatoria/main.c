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
    Programa: main.c es el fichero de prueba de todas las funciones desarrolla-
			  das para la parte obligatoria de la práctica.
    
*/
/*****************************************************************************/

#include <stdio.h>
#include "P1.h"

int main(){

	//funcion 1
	gotoxy(4,4);

	//función 2
	printf("\nCursor invisible: ");
   	setcursortype(0);
   	mi_pausa();
   	printf("\nCursor grueso: ");
   	setcursortype(2);
   	mi_pausa();
   	printf("\nCursor normal: ");
   	setcursortype(1);

	//funcion 3
	setvideomode(3);

	// funcion 4
	printf("El modo de video actual es: %d \n", getvideomode());
	
	
	// función 5
	textcolor(6);

	// fucnión 6
	textbackground(2);
	
	// función 7
	clrscr();

	// función 8
	cputchar('c');

	// función 9
	getche();

	return 0;
}