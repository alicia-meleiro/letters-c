
//Definicion de las funciones de operacion

#include <stdio.h>
#include <string.h>
#include "operation.h"
#include "inout.h"


int alta(abon abonados[], int* num){ //*num = numAbonados

  lee_cadena(abonados[*num].nombre, 15, "Nombre del abonado");

  if(*num == 0) abonados[*num].identidad = 1;
  else abonados[*num].identidad = abonados[*num-1].identidad + 1;

  //Si no hay abonados, la identidad del nuevo abonado es 1
  //Si hay abonados, la identidad del nuevo abonado es la identidad del último abonado +1
  
  abonados[*num].cuenta = 0;

  printf("\nNuevo abonado:\n");
  muestra_abonado(&abonados[*num]);
  
  (*num)++;
 
  return 0;
}

int escribir(abon abonados[],int numAbonados, men mensajes[], int *numMensajes){ 
  int id_emisor,id_destino,i,j,aux_emisor = 0,aux_destino = 0;
  
  if(numAbonados == 0){
    printf("No hay abonados\n\n");
    return 0;}

  id_emisor = lee_entero(abonados[numAbonados-1].identidad,"Identidad del emisor");

  printf("\n");

  for(i=0 ; i<numAbonados && aux_emisor == 0; i++) {
    if(id_emisor == abonados[i].identidad){ //Solo pide la identidad del destino si la del emisor coincide con alguna de la tabla
          id_destino = lee_entero(abonados[numAbonados-1].identidad,"Identidad del destino"); 
	       for(j=0 ; j<numAbonados && aux_destino == 0; j++){
	            if(id_destino == abonados[j].identidad){
		      aux_destino = 1;
		      //Esta variable auxiliar se inicializa si la identidad del destino introducida coincide con alguna de la tabla
	            }
               }
	       aux_emisor = 1;
	       //Esta variable auxiliar se inicializa si la identidad del emisor introducida coicide con alguna de la tabla
      }
  }

  if(aux_emisor == 0 || aux_destino == 0){
    printf("\nAbonado desconocido\n\n");
    return 0;}

  mensajes[*numMensajes].emisor = id_emisor;
  mensajes[*numMensajes].destino = id_destino;
  printf("\n");
  lee_cadena(mensajes[*numMensajes].texto,100,"Texto del mensaje");

  j--; //Lo hacemos para anular el ultimo j++ que se hizo con el for

  (abonados[j].cuenta)++;
    
  printf("\nAnotado mensaje:\n");
  muestra_extensa(&mensajes[*numMensajes]);

  (*numMensajes)++;
    
  return 0;
}

int listar(abon abonados[], int numAbonados,men mensajes[], int numMensajes){
  char n_destino[15];
  int i,j,aux = 0;
  
  if(numAbonados == 0){
    printf("\nNo hay abonados\n\n");
    return 0;}

  lee_cadena(n_destino,15,"Nombre del destino");

  for(i=0 ; i<numAbonados ; i++){
    if(!(strcmp(abonados[i].nombre,n_destino))){ //Compara si el nombre introducido es igual a alguno de la tabla
	aux = 1;
	printf("\nMensajes para %s:\n",abonados[i].nombre);
	for(j=0 ; j<numMensajes ; j++){
	  if(mensajes[j].destino == abonados[i].identidad){
	      muestra_corta(&mensajes[j]);
	  }
	}
	printf("\n");
      }
    }

  if(aux == 0){
      printf("\nAbonado desconocido\n\n");
      return 0;}
    
  return 0;
  
}

int borrar(abon abonados[], int numAbonados, men mensajes[], int *numMensajes){
  int i,j,cont = 0,aux = 0,id_destino,pos_mensaje;
  
  if(numAbonados == 0){
    printf("\nNo hay abonados\n\n");
    return 0;}
  
  id_destino = lee_entero(abonados[numAbonados-1].identidad,"Identidad del destino");

  for(i=0 ; i<numAbonados ; i++)
    if(id_destino == abonados[i].identidad){
      aux = 1;
      break;}
	 
  if(aux == 0){
    printf("\nAbonado desconocido\n\n");
    return 0;}
  
  if(abonados[i].cuenta == 0){
    printf("\nNo hay mensajes\n\n");
    return 0;}

  printf("\n");
  pos_mensaje = lee_entero(abonados[i].cuenta,"Posicion del mensaje");

  for(j=0 ; j<*numMensajes ; j++){
    if(mensajes[j].destino == id_destino) cont++; 
    if(cont == pos_mensaje){
       borrar_un_mensaje(mensajes,j,numMensajes);
       abonados[i].cuenta--;
       printf("\nMensaje borrado\n\n");
       break;
    }	  
  } 
  
  return 0;
}

int retirar(abon abonados[],int *numAbonados,men mensajes[],int *numMensajes){
  int i,j,aux = 0, id_destino;
  
  if(*numAbonados == 0){
    printf("\nNo hay abonados\n\n");
    return 0;}

  id_destino = lee_entero(abonados[*numAbonados-1].identidad,"Identidad del abonado");

  for(i=0 ; i<*numAbonados ; i++)
    if(id_destino == abonados[i].identidad){ //i indica la posicion del abonado a retirar
      aux = 1;
      break;}
  
  if(aux == 0){
    printf("\nAbonado desconocido\n\n");
    return 0;}

  for(j=0 ; j<*numMensajes ; j++){
    if(mensajes[j].destino == abonados[i].identidad){ //j indica la posicion del mensaje a retirar
      borrar_un_mensaje(mensajes,j,numMensajes);
      j--;
    }
  }

  borrar_un_abonado(abonados,i,numAbonados);

  return 0;
}

int salir(abon abonados[], int numAbonados, men mensajes[], int numMensajes){
  int salida = 0;
  
  salida = confirmar("Seguro que desea salir del programa? (s/n):");
      //confirmar() devuelve 1 si tecleamos "s", es decir, el usuario confirma que desea salir

  if(salida == 1){
	escribe_abonados(abonados,numAbonados);
	escribe_mensajes(mensajes,numMensajes);
	//Solo escribe en los ficheros de abonados y mensajes si el usuario confirma que desea salir (si confirmar () devuelve 1)
      }

  return salida;
}
