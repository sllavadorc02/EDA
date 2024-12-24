pruebaColas: pruebaColas.o cola.o
	gcc -g pruebaColas.o cola.o -o pruebaColas
pruebaColas.o: pruebaColas.c cola.h
	gcc -g -c pruebaColas.c
cola.o: cola.c cola.h
	gcc -g -c cola.c
limpiar:
	rm pruebaColas.o cola.o