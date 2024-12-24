# Proyecto para entrega Tipos Abstractos de Datos 2023
#
# ( Añadir las reglas necesarias para la correcta compilación de todas las implementaciones que se piden)


pruebaInsercion: pruebaInsercion.o lista.o insercion.o
	gcc -g pruebaInsercion.o lista.o insercion.o -o pruebaInsercion
	
pruebaInsercion.o: pruebaInsercion.c lista.h insercion.h 
	gcc -g -c pruebaInsercion.c 

insercion.o: insercion.c insercion.h lista.h 
	gcc -g -c insercion.c 

lista.o: lista.c lista.h 
	gcc -g -c lista.c -o lista.o 

medirTyContarInsercion: medirTyContarInsercion.o lista.o insercion.o
	gcc -g medirTyContarInsercion.o lista.o insercion.o -o medirTyContarInsercion

medirTyContarInsercion.o: medirTyContarInsercion.c lista.h insercion.h
	gcc -g -c medirTyContarInsercion.c 
	
limpiar:
	rm *.o lista.o	
	
