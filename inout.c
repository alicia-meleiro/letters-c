
//Definicion de las funciones del modulo de entrada/salida 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "operation.h"
#include "inout.h"


void plano(char caracter, int n){
  int i;

  for(i=0 ; i<n ; i++){
    printf("%c",caracter);}
  
  printf("\n");
  
}

void rotulo(char texto[50], char caracter, int n){
  int i,distancia;

  distancia = n - (strlen(texto) + 2);
  
  printf("%c",caracter);              //Imprime el primer caracter
  for(i=0 ; i < (distancia/2) ; i++){ //Imprime espacios
    printf(" ");}
  printf("%s",texto);                 //Imprime el texto centrado
  for(i=0 ; i < (distancia/2) ; i++){ //Imprime espacios
    printf(" ");}
  printf("%c",caracter);              //Imprime el ultimo caracter
  printf("\n");
}

int confirmar(char *mensaje){
  char letra; 
  char cadena[50],error[50],espacio;
  int i;

  //letra guarda la respuesta
  //cadena guarda una posible cadena de caracteres introducida por error
  //espacio guarda el '\n' que se introduce al pulsar intro

  do{
    do{
      printf("%s",mensaje);
    
      fgets(cadena,50,stdin);
      i = sscanf(cadena,"%c%s%c",&letra,error,&espacio);

      printf("\n");
      
    }while(i == 3);
    

    if(tolower(letra) == 's')return 1;
    else if(tolower(letra) == 'n')return 0;

  }while(tolower(letra) != 's' || tolower(letra) != 'n');

}


void lee_cadena(char *la_cadena, int N, char *mensaje){
  char nombre[250],cadena_aux[250],espacio = '0';
  int i;

  do{
    printf("%s (1-%i car):",mensaje,N); 
    fgets(nombre,250,stdin); 
    i = sscanf(nombre,"%s%c",cadena_aux,&espacio);
 
    if(i == -1) printf("\nLongitud nula\n\n");
    else if(strlen(cadena_aux) > N){
         printf("\nLongitud excesiva\n\n");
         //while(fgetc(stdin) != '\n');
    }
    else strcpy(la_cadena,cadena_aux);
    
  }while(i != 2 || strlen(cadena_aux) > N);

  return;
}

int lee_entero(int N, char *mensaje){
  int entero,i;
  char cadena[50],error[50],espacio;

  //entero guarda el numero buscado
  //error guarda una posible cadena de caracteres introducida por error 
  //espacio guarda el '\n' que se introduce al pulsar intro

  do{
    printf("%s [1-%i]:",mensaje,N);
    fgets(cadena,50,stdin);
    i = sscanf(cadena,"%i%s%c",&entero,error,&espacio);

    if(i != 1 || entero>N || entero<1) printf("\nValor incorrecto\n\n");
    
  }while(i != 1 || entero>N || entero<1);

  return entero;
}

int lee_abonados(abon abonados[]){
    FILE *f_abonados = fopen("abonados.txt","r");
    char linea[100];
    int i=0,cont; //i es el numero de abonados

    if(f_abonados == NULL) return 0;
      
    while(fgets(linea,100,f_abonados)){
	cont = sscanf(linea,"%i%i%s",&abonados[i].identidad,&abonados[i].cuenta,abonados[i].nombre);
	if(cont == 3)i++;
    }
      
    fclose(f_abonados);
    return i;
}

int lee_mensajes(men mensajes[]){
    FILE *f_mensajes = fopen("mensajes.txt","r");
    char linea[200];
    int i=0,cont; //i es el numero de mensajes

    if(f_mensajes == NULL) return 0;
     
    while(fgets(linea,200,f_mensajes)){
        cont = sscanf(linea,"%i%i%s",&mensajes[i].emisor,&mensajes[i].destino,mensajes[i].texto);
	if(cont == 3)i++;
    }
    
    fclose(f_mensajes);
    return i;
}

void escribe_abonados(abon abonados[],int numAbonados){
  FILE *f_abonados = fopen("abonados.txt","w");
  int i;

  for(i=0 ; i<numAbonados ; i++){
    fprintf(f_abonados,"%i ",abonados[i].identidad);
    fprintf(f_abonados,"%i ",abonados[i].cuenta);
    fprintf(f_abonados,"%s\n",abonados[i].nombre);
  }
  
  fclose(f_abonados);
  return;
}
    
void escribe_mensajes(men mensajes[],int numMensajes){
  FILE *f_mensajes = fopen("mensajes.txt","w");
  int i;

  for(i=0 ; i<numMensajes ; i++){
    fprintf(f_mensajes,"%i ",mensajes[i].emisor);
    fprintf(f_mensajes,"%i ",mensajes[i].destino);
    fprintf(f_mensajes,"%s\n",mensajes[i].texto);
  }

  fclose(f_mensajes);
  return;
}

void borrar_un_abonado(abon abonados[],int i,int *numAbonados){
  memmove(&abonados[i],&abonados[i+1],((*numAbonados)-1-i)*sizeof(abon));
  (*numAbonados)--;
  printf("\nAbonado retirado\n\n");

  return;
}

void borrar_un_mensaje(men mensajes[],int i, int *numMensajes){
  memmove(&mensajes[i],&mensajes[i+1],((*numMensajes)-1-i)*sizeof(men));
  (*numMensajes)--;
  
  return;
}

void muestra_abonado(abon *abonados){
  printf("#%3i:%15s\n\n",abonados->identidad,abonados->nombre);
       
  return;
}

void muestra_extensa(men *mensajes){
  printf("> Emisor: %i\n",mensajes->emisor);
  printf("> Destino: %i\n",mensajes->destino);
  printf("> Texto: %s\n\n",mensajes->texto);
 
  return;
}

void muestra_corta(men *mensajes){
  int j, longitud;

  longitud = strlen(mensajes->texto);

  printf("#%3i:%3i:",mensajes->emisor,mensajes->destino);
  
  if(longitud <= 12) printf("%s\n",mensajes->texto);

  else{
    for(j=0 ; j<12 ; j++) printf("%c",mensajes->texto[j]);
    printf("\n");
  }

  return;
}






