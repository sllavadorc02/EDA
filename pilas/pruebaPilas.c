#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main (void){
    Pila pila;
    pilaCreaVacia(&pila);

   

    printf("\nSe hace la insercion...\n");
    pilaInserta(&pila, 1);
    imprimir(&pila);
    pilaInserta(&pila, 2);
    imprimir(&pila);
    pilaInserta(&pila, 3);
    imprimir(&pila);
    
    
    
    printf("\n\nEn la lista hay guardado:\n");
    imprimir(&pila);
    

    pilaSuprime(&pila);
    imprimir(&pila);
    pilaSuprime(&pila);
    imprimir(&pila);
    pilaSuprime(&pila);
    imprimir(&pila);
    

    
    printf("\n\nDespues de suprimir:\n");
    imprimir(&pila);
    printf("\n");

    liberar(&pila);

    return 0;
}