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
	Biblioteca: p1.h fichero de cabeceras (interfaz) de las funciones 
				desarrolladas en la parte obligatoria de la práctica. 
*/
/*****************************************************************************/


//coloca el cursor en una posición determinada por x e y.
void gotoxy(int x, int y);

//Fija el aspecto del cursor admitiendo tres valores.
void setcursortype(int tipo_cursor);

//fija el modo de vídea deseado por modo
void setvideomode( unsigned char modo);

//obtiene el modo de video actual
int getvideomode();

//Modifica el color de primer plano con que se mostrar� los caracteres.
void textcolor(int  color);

//Modifica el color de fondo con que se mostrar�n los caracteres.
void textbackground(int color);

// Borra toda la pantalla.
void clrscr();

//escribe un carácter en pantalla con el color indicado actualmente
void cputchar(unsigned char c);

//Obtiene un carácter de teclado
int mi_getchar();
//Establece el caracter que se le pasa por pantalla
void mi_putchar(char caracter);

//obtiene un carácter de teclado y lo muestra en pantalla
void getche();

//pausa para poder leer la pantalla.
void mi_pausa();

