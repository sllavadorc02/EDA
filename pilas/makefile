pruebaPilas: pruebaPilas.o pila.o
	gcc -g pruebaPilas.o pila.o -o pruebaPilas
pruebaPilas.o: pruebaPilas.c pila.h
	gcc -g -c pruebaPilas.c
pila.o: pila.c pila.h
	gcc -g -c pila.c
limpiar:
	rm pruebaPilas.o pila.o