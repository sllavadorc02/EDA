#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "insercion.h"

long int contadorInterno, contadorExterno, contadorMedio;

void insercion(Lista *l) {
    if (l == NULL || vacia(l) == 1) {
        return;
    }

    Lista desordenada;
    tipoElemento elemento;

    // Crear las listas vacías
    creaVacia(&desordenada);

    // Dividir la lista original en ordenada y desordenada
    dividirLista(l, primero(l), &desordenada);  

    
    while(vacia(&desordenada)==0){

        tipoPosicion lugar=primero(l);
        tipoPosicion primeraDesordenada=primero(&desordenada);

        if(recupera(primeraDesordenada, &desordenada) > recuperaUltimo(l)){
    
            int error= traspasarNodo(primeraDesordenada, &desordenada, localiza(recuperaUltimo(l), l), l);
            if(error != 0){
                printf("Hubo un error: %d", error);
            }
            

        }else{

            while( siguiente(lugar,l) !=NULL && (recupera(lugar, l) < recupera(primeraDesordenada, &desordenada))){
                lugar=siguiente(lugar, l);
            }

            int error= traspasarNodo(primeraDesordenada, &desordenada, lugar, l);
            if(error != 0){
                printf("Hubo un error: %d", error);
            }
        }
        

    }

    

}
