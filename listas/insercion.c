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
    

    while (desordenada.raiz->sig != NULL) {  // Mientras haya elementos en la lista desordenada
        
        tipoCelda *nodoDesordenado = desordenada.raiz->sig;
        tipoElemento elemento = nodoDesordenado->elemento;

        
        tipoPosicion lugar = ordenada.raiz; 
         
        while (lugar->sig != NULL) {         // Verificar si lugar->sig es válido
            if(lugar->sig->elemento >= elemento){
                break;
            }
            lugar = lugar->sig;  // Avanzamos al siguiente nodo
        }

        // Insertamos el elemento en la posición correcta de la lista ordenada
        inserta(elemento, lugar, &ordenada);
        
        // Ahora, eliminamos el nodo procesado de la lista desordenada
        desordenada.raiz->sig = nodoDesordenado->sig;  // Avanzamos al siguiente nodo
        free(nodoDesordenado);
        
    }

    


}
