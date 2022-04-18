#ifndef INOUT
#define INOUT

//Fichero de cabecera con la declaracion de funciones

void plano(char, int);
void rotulo(char*, char, int);
int confirmar(char*);

void lee_cadena(char*,int,char*);
int lee_entero(int,char*);

int lee_abonados(abon*);
int lee_mensajes(men*);
void escribe_abonados(abon*,int);
void escribe_mensajes(men*,int);

void borrar_un_abonado(abon*,int,int*);
void borrar_un_mensaje(men*,int, int*);

void muestra_abonado(abon*);
void muestra_extensa(men*);
void muestra_corta(men*);

#endif
