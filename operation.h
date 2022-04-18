
#ifndef OPERATION
#define OPERATION

//Declaracion de las struct usadas
typedef struct unAbonado{ //abonados
  int identidad;
  int cuenta;
  char nombre[15];
}abon;

typedef struct unMensaje{ //mensajes
  int emisor;
  int destino;
  char texto[100];
}men;


//Declaracion de las funciones del modulo "operation"
int alta(abon*, int*);
int escribir(abon*, int, men*, int*);
int listar(abon*, int, men*, int);
int borrar(abon*, int, men*, int*);
int retirar(abon*, int*, men*,int*);
int salir(abon*, int, men*, int);

#endif
