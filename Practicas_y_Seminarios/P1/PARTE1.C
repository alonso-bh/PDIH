// -gotoxy(): coloca el cursor en una posición determinada
// setcursortype(): fijar el aspecto del cursor, debe admitir tres valores: INVISIBLE, NORMAL y GRUESO.
// -setvideomode(): fija el modo de video deseado
// -getvideomode(): obtiene el modo de video actual
// textcolor(): modifica el color de primer plano con que se mostrarán los caracteres
// textbackground(): modifica el color de fondo con que se mostrarán los caracteres
// clrscr(): borra toda la pantalla
// cputchar(): escribe un carácter en pantalla con el color indicado actualmente
// getche():obtiene un carácter de teclado y lo muestra en pantalla

#include <dos.h>
#include <stdio.h>


#define BYTE unsigned char


// funcion 1. gotoxy()
void gotoxy(int x, int y){
	union REGS inregs, outregs;

	inregs.h.ah=2;
	inregs.h.dh=x;
	inregs.h.dl=y;
	inregs.h.bh=0;

	int86(0x10, &inregs, &outregs);
}


// función 3. setvideomode() fijar el modo de vídeo deseado
void setvideomode(BYTE modo){
	union REGS inregs, outregs;

	inregs.h.ah=0x00;
	inregs.h.al=modo;

	int86(0x10, &inregs, &outregs);
}

// funcion 4. getvideomode() obtener el modo de video actual
int getvideomode(){
	union REGS inregs, outregs;

	inregs.h.ah = 0x0f;

	int86(0x10, &inregs, &outregs);
	return outregs.h.al;
}


// main (debe ir separado en otro fichero para hacer la biblioteca)
void main(){

	// funcion 1
	gotoxy(4,4);
	//printf("\nLínea tras volver a posicionar\n");

	// funcion 3
	//setvideomode(4);

	// funcion 4
	//printf("El modo de video actual es: %d", getvideomode());

}


