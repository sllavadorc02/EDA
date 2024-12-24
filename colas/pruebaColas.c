#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main (void){
    Cola cola;
    colaCreaVacia(&cola);

    printf("\nSe hace la insercion...\n");
    colaInserta(&cola, 1);
    imprimir(&cola);
    colaInserta(&cola, 2);
    imprimir(&cola);
    colaInserta(&cola, 3);
    imprimir(&cola);
    
    
    printf("\n\nEn la lista hay guardado:\n");
    imprimir(&cola);
    
    colaSuprime(&cola);
    imprimir(&cola);
    colaSuprime(&cola);
    imprimir(&cola);
    //colaSuprime(&cola);
    //imprimir(&cola);
    
    

    printf("\n\nDespues de suprimir:\n");
    imprimir(&cola);


    printf("\n");
    return 0;
}