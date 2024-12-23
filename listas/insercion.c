#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "insercion.h"

void insercion(Lista *l){
    if(l==NULL || vacia(l)==1){
        return;
    
    }

    Lista ordenada, desordenada;
    tipoPosicion pos, lugar;
    tipoElemento elemento;

    creaVacia(&ordenada);
    creaVacia(&desordenada);

    dividirLista(l, primero(l), &desordenada);

    while(vacia(&desordenada)==0){
        pos=primero(&desordenada);
        elemento=recupera(pos, &desordenada);

        lugar=primero(&ordenada);
        while (lugar != fin(&ordenada) && recupera(lugar, &ordenada) < elemento) {
            lugar = siguiente(lugar, &ordenada);
        }

        traspasarNodo(pos, &desordenada, lugar, &ordenada);
    }

    //anula(l); //original vacía
    pos = primero(&ordenada);
    while (pos != fin(&ordenada)) {
        inserta(recupera(pos, &ordenada), fin(l), l);
        pos = pos->sig;
    }
    
    // Liberar la memoria utilizada por las sublistas
    anula(&ordenada);
    destruye(&ordenada);
    destruye(&desordenada);




}