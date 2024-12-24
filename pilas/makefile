pruebaPila: pruebaPila.o pila.o
	gcc -g pruebaPila.o pila.o -o pruebaPila
pruebaPila.o: pruebaPila.c pila.h
	gcc -g -c pruebaPila.c
pila.o: pila.c pila.h
	gcc -g -c pila.c
limpiar:
	rm *.o lista.o