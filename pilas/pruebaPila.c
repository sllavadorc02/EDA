#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main (void){
    Pila pila;
    pilaCreaVacia(&pila);

   

    printf("\nSe hace la insercion...");
    pilaInserta(&pila, 1);
    pilaInserta(&pila, 2);
    pilaInserta(&pila, 3);
    
    

    

    tipoCelda *imprimir;
    printf("\n\nEn la lista hay guardado:\n");
    
    if(pilaVacia(&pila)==0){
        printf("La pila esta vacia...");
    }else{
        imprimir=pila;
        while(imprimir!=NULL){
            printf("%d ", imprimir->elemento);
            imprimir=imprimir->sig;
        }
    }
    

    pilaSuprime(&pila);
    //pilaSuprime(&pila);
    //pilaSuprime(&pila);

    
    printf("\n\nDespues de suprimir:\n");

    if(pilaVacia(&pila)==0){
        printf("La pila esta vacia...");
    }else{
        imprimir=pila;
        while(imprimir!=NULL){
            printf("%d ", imprimir->elemento);
            imprimir=imprimir->sig;
        }
    }

    printf("\n");



    return 0;
}