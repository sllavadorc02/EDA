#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p){
    if(p==NULL){
        return -1;
    }

    *p=NULL;
    return 0;
}


int pilaVacia(Pila *p){
    if(*p==NULL || p==NULL){
        return 0;
    }
    
    return -1;
}


int pilaInserta(Pila *p,tipoElemento elemento){
    if(p==NULL){
        return -1;
    }


    tipoCelda *nuevo=(tipoCelda *)malloc(sizeof(tipoCelda));
    if(nuevo== NULL){
        return -2;
    }

    nuevo->elemento=elemento;
    nuevo->sig=*p;
    *p=nuevo;

    return 0;
}

tipoElemento pilaSuprime(Pila *p){
   if(*p==NULL || p==NULL){
        return -1;
   }
    tipoElemento el;
    tipoCelda *aBorrar;
    aBorrar=*p;
    *p=aBorrar->sig;
    el=aBorrar->elemento;
    free(aBorrar);

    return el;

}
