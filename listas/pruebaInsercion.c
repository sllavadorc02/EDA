#include <stdio.h>
#include <stdlib.h>
#include "insercion.h"
#include "lista.h"

	

int main(int argc, char *argv[]){   
	Lista miLista;
	tipoPosicion p;
	int numElementos = 20, codigoError,i;

	if (argc > 2) {
		printf("\n Uso: ./pruebaInsercion <número de elementos de la lista>\n\n");
		return -1;
	}
	if (argc==2) 
		numElementos=atoi(argv[1]); 

	printf("Creando lista vacía: %d\n", creaVacia(&miLista));

	printf("Se crea una lista de %d elementos:\n", numElementos);
	anula(&miLista);	
	p = primero(&miLista);
	for (i = 0; i < numElementos; i++) { 
		codigoError = inserta(rand()%100000,p,&miLista);
		p = siguiente(p,&miLista);
	}
	imprime(&miLista);
	printf("\n\nComienza la ordenación \n");
	insercion(&miLista);
	printf("\nLista Ordenada: \n");
	imprime(&miLista);
	anula(&miLista);

	
	destruye(&miLista); 
	return 0;
}

