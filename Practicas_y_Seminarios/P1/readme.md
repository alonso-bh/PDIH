# Práctica 1: E/S con interrupciones en C

Alumnos:
* Alonso Bueno Herrero
* Bartolomé Zambrana Pérez

## Ejercicios obligatorios

Desarrollo de las siguientes funciones:

### `gotoxy(x,y)` 

Para mover el cursor a la posición (x,y) de la pantalla. 

```C
void gotoxy(int x, int y){
	union REGS inregs, outregs;

	inregs.h.ah=2;
	inregs.h.dh=x;
	inregs.h.dl=y;
	inregs.h.bh=0;

	int86(0x10, &inregs, &outregs);
}
```

### setcursortype()

Fijar uno de los 3 tipos de cursores disponibles. 

```C

```

### setvideomode(BYTE modo) 

Para establecer el modo de vídeo a usar. Para ver los modos válidos, repasar tabla del guión de la Práctica 1.

```C
void setvideomode(BYTE modo){
	union REGS inregs, outregs;

	inregs.h.ah=0x00;
	inregs.h.al=modo;

	int86(0x10, &inregs, &outregs);
}
```




###  `getvideotype()` 

Obtener el modo de vídeo actual. 



```C
int getvideomode(){
	union REGS inregs, outregs;

	inregs.h.ah = 0x0f;

	int86(0x10, &inregs, &outregs);
	return outregs.h.al;
}
```