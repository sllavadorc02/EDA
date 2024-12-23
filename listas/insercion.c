#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "insercion.h"

void insercion(Lista *l) {
    if (l == NULL || vacia(l) == 1) {
        return;
    }

    Lista ordenada, desordenada;
    tipoPosicion pos, lugar;
    tipoElemento elemento;

    creaVacia(&ordenada);
    creaVacia(&desordenada);

    dividirLista(l, l->raiz->sig, &desordenada);
    ordenada.raiz=l->raiz;
    ordenada.ultimo=l->ultimo;
    

    while (desordenada.raiz->sig != NULL) { 
        
        tipoCelda *nodoDesordenado = desordenada.raiz->sig;
        tipoElemento elemento = nodoDesordenado->elemento;
        tipoPosicion lugar = ordenada.raiz; 
         
        while (lugar->sig != NULL) {         
            if(lugar->sig->elemento >= elemento){
                break;
            }
            lugar = lugar->sig; 
        }

        inserta(elemento, lugar, &ordenada);
        desordenada.raiz->sig = nodoDesordenado->sig;  
        free(nodoDesordenado);
        
    }

    


}
