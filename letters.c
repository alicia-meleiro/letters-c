
//Alicia Meleiro Estevez, 1ºB

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "operation.h"
#include "inout.h"


#define ALTA 'A'
#define ESCRIBIR 'E'
#define LISTAR 'L'
#define BORRAR 'B'
#define RETIRAR 'J'
#define SALIR 'S'

int main(){
  abon losAbonados[200];
  men losMensajes[300];
  int numAbonados = 0, numMensajes = 0;
  //Estas cuatro son las principales variables del programa
  //abon es el tipo struct unAbonado
  //men es el tipo struct unMensaje
  
  char letra,espacio,cadena[50],error[50];
  int salida = 0,i;

//CARATULA DEL PROGRAMA
  plano('+',60);
  rotulo("CARTAS",'+',60);
  plano('+',60);

  printf("\n");

//LECTURA DE FICHEROS
  numAbonados = lee_abonados(losAbonados);

  if(numAbonados != 0) numMensajes = lee_mensajes(losMensajes);
  //El fichero de mensajes solo se lee si el de abonados no esta vacio

//INTERFAZ DE USUARIO
  do{
    do{
      printf("A) Dar de alta a un abonado\n");
      printf("E) Escribir un mensaje\n");
      printf("L) Listar los mensajes para un abonado\n");
      printf("B) Borrar un mensaje\n");
      printf("J) Dar de baja a un abonado\n\n");
      printf("S) Salir del programa\n\n");

      printf("Elige una opcion:");

      fgets(cadena,50,stdin);
      i = sscanf(cadena,"%c%s%c",&letra,error,&espacio);

      printf("\n");

      if(i == 3)printf("Has elegido una opcion invalida\n\n");
      //Este if se ejecuta si escribimos un caracter correcto seguido de, por ejemplo, una cadena de caracteres, como cuando tecleamos "escribir"

    }while(i == 3);
    
    letra = toupper(letra);

    switch(letra){
    case ALTA:
      printf("Suscribir\n\n");
      alta(losAbonados,&numAbonados);  
      break;
    
    case ESCRIBIR:
      printf("Escribir\n\n");
      escribir(losAbonados,numAbonados,losMensajes,&numMensajes);
      break;
    
    case LISTAR:
      printf("Listar\n\n");
      listar(losAbonados,numAbonados,losMensajes,numMensajes);
      break;
    
    case BORRAR:
      printf("Borrar\n\n");
      borrar(losAbonados,numAbonados,losMensajes,&numMensajes);
      break;
    
    case RETIRAR:
      printf("Retirar\n\n");
      retirar(losAbonados,&numAbonados,losMensajes,&numMensajes);
      break;
 
    case SALIR:
      printf("Salir\n\n");
      salida = salir(losAbonados,numAbonados,losMensajes,numMensajes);
      break;
    
    default:
      printf("Has elegido una opcion invalida\n\n");
      break;
    
    }
    
    }while(salida == 0);
  //Una vez el usuario confirma que desea salir, confirmar() devuelve 1, y, por tanto, la variable salida vale 1, por lo que sale de la interfaz de usuario

  return 0;
}
