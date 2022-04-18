
#Fichero Makefile para compilar automaticamente letters.c

CC = gcc -Wall

all: letters

inout.o: inout.c inout.h
	$(CC) -c inout.c
operation.o: operation.c operation.h
	$(CC) -c operation.c
letters: inout.o operation.o
	$(CC) inout.o operation.o letters.c -o letters

clean:
	rm -f letters *o. *~ *.bak 
