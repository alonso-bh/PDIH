# Seminario 1: Programación de dispositivos a bajo nivel

Solución de los ejercicios propuestos.

ALUMNOS:
* Alonso Bueno Herrero
* Bartolomé Zambrana Pérez

## Ejercicio 1. Instalar el software DOSBox y ejecutar aplicaciones de MS-DOS (p.ej. juegos clásicos).

Tras instalar el ejecutable, hay que abrir el fichero de configuración, ubicado en mi caso en `C:\Users\UX430U\AppData\Local\DOSBox\dosbox-0.74-3.conf` y añadir, al final, el siguiente contenido:

```
[autoexec]
# Lines in this section will be run at startup.
# You can put your MOUNT lines here. 
# (Alonso Bueno Herrero, 2021)
keyb sp
mount C C:\Users\UX430U\OneDrive\CUARTO_CURSO\PDIH\Practicas_y_Seminarios\bc
path C:\bc\BIN
```



## Ejercicio 2. Configurar el inicio de DOSBox para que monte en la unidad C: el directorio donde se encuentra el entorno de programación Borland C (que incluye las herramientas para compilar no sólo lenguaje C, sino también ensamblador). Añadir a la variable “PATH” de inicio el directorio “bin” donde se encuentra el ejecutable BC.EXE. 

--

## Ejercicio 3. Crear el ejemplo “Hola mundo” en ensamblador, compilarlo y comprobar su funcionamiento. A continuación incluir un bucle para mostrar el mensaje 7 veces.

Tras descargar los ficheros de prueba del Seminario, he ejecutado el script `hola.asm` disponible. Para la compilación, una vez configurado el *path* del emulador y demás, he usado también el fichero `c.bat`. Para la compilación de nuestro fichero se ha usado la línea siguiente:

```
C:\S1\ejemplos>c.bat hola
```

