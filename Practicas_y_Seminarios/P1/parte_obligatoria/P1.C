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
    Biblioteca: p1.C implementa las funcionalidades de la parte obligatoria
	            de la práctica. 
    
*/
/*****************************************************************************/


#include <dos.h>
#include "P1.h"

/*** VARIABLES PARA ESTABLECER COLORES ***/
int text_color = 15; 		//Blanco por defecto.
int background_color = 0;  	//Negro por defecto.

//Obtiene un caracter de la pantalla
int mi_getchar(){
	union REGS inregs, outregs;
	int caracter;

	inregs.h.ah = 1;
	int86(0x21, &inregs, &outregs);

	caracter = outregs.h.al;
	return caracter;
}
//Establece el caracter que se le pasa por pantalla
void mi_putchar(char caracter){
	union REGS inregs, outregs;

	inregs.h.ah = 2;
	inregs.h.dl = caracter;
	int86(0x21, &inregs, &outregs);
}

//Se hace uso de las implementacions anteriorioes para realizarlo
void getche(){
	int temporary;
	temporary = mi_getchar();
	mi_putchar((char)temporary );
	printf("\n");

}


//Modifica el color de primer plano con que se mostrar� los caracteres.
void textcolor(int  color){
	text_color = color;
}

//Modifica el color de fondo con que se mostrar�n los caracteres.
void textbackground(int color){
	background_color = color;
}

void gotoxy(int x, int y){
	union REGS inregs, outregs;

	inregs.h.ah = 2;
	inregs.h.dh = x;
	inregs.h.dl = y;
	inregs.h.bh = 0;
	int86(0x10, &inregs, &outregs);
}


void mi_pausa(){
	union REGS inregs, outregs;
	inregs.h.ah = 8;
	int86(0x21,&inregs, &outregs);
}

int getvideomode(){
	union REGS inregs, outregs;
	inregs.h.ah = 0xF;
	int86(0x10, &inregs, &outregs);
	//Devolvemos modo en el que se encuentra.
	return outregs.h.al;
}

void setvideomode( unsigned char modo){
	union REGS inregs, outregs;
	inregs.h.ah=0x00;
	inregs.h.al=modo;

	int86(0x10, &inregs, &outregs);
}


// Borra toda la pantalla.
void clrscr(){
	int modo; //Variable para mostar el modo
	int i;
	modo = getvideomode();

	//Realizamos el clear si se encuentra en
	//modo texto, sino no tiene sentido.
	if(modo == 0 || modo == 1 || modo == 2 ||
		 modo == 3 || modo == 7){

		//Todos los modo texto tienen 25 l�neas.

		for( i = 0; i < 24 ; i++)
		printf("\n");

		gotoxy(0,0);
	}


}


//Escribir el caracter pasado como parámetro con el color actual.
void cputchar(unsigned char c){
	union REGS inregs, outregs;
	inregs.h.ah = 0x09;
	inregs.h.al = c;
	inregs.h.bl = background_color << 4 | text_color;
	inregs.h.bh = 0x00;
	inregs.x.cx = 1;
	int86(0x10,&inregs,&outregs);
}


//Fija el aspecto del cursor admitiendo tres valores.
void setcursortype(int tipo_cursor){
	union REGS inregs, outregs;
	inregs.h.ah = 0x01;
	switch(tipo_cursor){
		case 0: //invisible
			inregs.h.ch = 010;
			inregs.h.cl = 000;
			break;
		case 1: //normal
			inregs.h.ch = 010;
			inregs.h.cl = 010;
			break;
		case 2: //grueso
			inregs.h.ch = 000;
			inregs.h.cl = 010;
			break;
	}
	int86(0x10, &inregs, &outregs);
}


