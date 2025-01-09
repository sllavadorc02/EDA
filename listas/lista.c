#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"

int creaVacia(Lista *l){
    if (l == NULL)
        return -2;
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda)))){
        return -1;
    }else {
        l->raiz->sig = NULL;
        return 0;
    }
}


int anula(Lista *l){
    tipoPosicion q, aBorrar;
    q=l->raiz->sig;
    l->raiz->sig=NULL;
    while(q !=NULL){
    	aBorrar=q;
    	q=q->sig;
    	free(aBorrar);
    }
    return 0;
}


int vacia(Lista *l){
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }else if (l->raiz->sig == NULL){
        return 1;
    }else{
        return 0;
    }
}


int inserta(tipoElemento x, tipoPosicion p, Lista *l){
    tipoCelda *nuevo;
    
    if(l == NULL) {
        fprintf(stderr,"Fallo precondición lista no existente!\n");
        return -1;
    }else if (l->raiz == NULL) {
        fprintf(stderr,"Fallo precondición nodo ficticio no existente!\n");
        return -2;
    }else if (p == NULL){
        fprintf(stderr,"Fallo precondición posición no válida!\n");
        return -3;
    }else if (NULL == (nuevo = (tipoCelda*)malloc(sizeof(tipoCelda)))) {
        fprintf(stderr,"Fallo reserva memoria!\n");
        return -4;
    }else {
        nuevo->elemento = x;
        nuevo->sig = p->sig;
        p->sig = nuevo;
        if (p == l->ultimo)
            l->ultimo = nuevo; //no esta en las transparencias (como en suprime tb)
        return 0;
    }
}


int suprime (tipoPosicion p, Lista *l){
    tipoPosicion aux; //o puntero a tipocelda
    
    if (l == NULL) { //lista no vacia
        fprintf(stderr,"Fallo precondición lista no existente!\n");
        return -1;
    }else if (l->raiz == NULL) { //inicio no nulo
        fprintf(stderr,"Fallo precondición nodo ficticio no existente!\n");
        return -2;
    }else if (p == NULL){ //posicion no nula
        fprintf(stderr,"Fallo precondición posición no válida!\n");
        return -3;
    }else if (p==l->ultimo) { //resultado no definido, fallo
        fprintf(stderr,"Fallo posicion fin !!!\n");
        return -5;
    }else {
       	aux=p->sig;
        p->sig=aux->sig;
        free(aux);
        if(p->sig==NULL){
        	l->ultimo=p;
        }
	    return 0;
    }

//si elimino el ultimo elemento de la lista tengo que cambiar a donde apunta l.ultimo

}

tipoPosicion localiza (tipoElemento x, Lista *l){
	tipoPosicion q;
	q=l->raiz;
	while(q->sig != NULL){
		if(q->sig->elemento ==x){
			return q;
		}
		q=q->sig;
	}
	
	return q;
}

tipoElemento recupera(tipoPosicion p, Lista *l){
    
    if (l == NULL) {
        fprintf(stderr,"Fallo precondición lista no existente!\n");
        return -1;
    }else if (l->raiz == NULL) {
        fprintf(stderr,"Fallo precondición nodo ficticio no existente!\n");
        return -2;
    }else if (p == NULL){
        fprintf(stderr,"Fallo precondición posición no válida!\n");
        return -3;
    }else if (p==l->ultimo) {
        fprintf(stderr,"Fallo posicion fin !!!\n");
        return -5;
    }else {
        return p->sig->elemento;
    }
   
}


tipoPosicion primero(Lista *l){
 if (l == NULL) {
        fprintf(stderr,"Fallo precondición lista no existente!\n");
        return NULL;
    }else if(l->raiz == NULL){
        fprintf(stderr,"Fallo precondición lista no inicializada!\n");
        return NULL;
    }else{
        return l->raiz;
    }
}


tipoPosicion siguiente(tipoPosicion p,Lista *l){
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }else if (p == l->ultimo){
        return NULL;
    }else{
        return p->sig;
    }
   
    
}


tipoPosicion anterior(tipoPosicion p, Lista *l){
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }else if (p == l->raiz){
        return l->raiz;
    }else {
        anterior = l->raiz;
        while (anterior->sig != p){
            anterior = anterior->sig;
        }
        return anterior;
    }
}


tipoPosicion fin(Lista *l){
    if (l == NULL) {
        fprintf(stderr,"Fallo precondición lista no existente!\n");
        return NULL;
    }else if (l->ultimo == NULL){
        fprintf(stderr,"Fallo precondición lista no existente!\n");
        return NULL;
    }else{
        return l->ultimo;
    }
}


void imprime(Lista *l){
    tipoCelda *aImprimir;

    
    if (l == NULL || l->raiz == NULL) {
        return;
    }else {
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
            printf(" %d ",aImprimir->elemento);
            aImprimir = aImprimir->sig;
        }
    }
}


int destruye(Lista *l){
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }else if (l->raiz->sig != NULL){
        return -2;
    }else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}


tipoElemento recuperaUltimo(Lista *l){
    if(l->raiz == NULL){
        return -1;
    }else{
        return l->ultimo->elemento; 
    }

}


int traspasarNodo(tipoPosicion p, Lista *la, tipoPosicion q, Lista *lb){
    if(la == NULL || lb == NULL){
        return -1;
    }else if(la->raiz == NULL || lb->raiz ==NULL){
        return -2;
    }else if(p==NULL || q==NULL || p->sig ==NULL){
        return -3;
    }else{
        tipoPosicion aux=p->sig;
        p->sig=aux->sig;
        aux->sig=q->sig;
        q->sig=aux;

        return 0;

    }

}


int dividirLista(Lista *lOrigen, tipoPosicion p, Lista *lNueva) {
    if (lOrigen == NULL || lNueva == NULL || p == NULL) {
        return -1;  
    }

    if (lOrigen->raiz == NULL || lOrigen->raiz->sig == NULL) {
        return -2; 
    }

    tipoPosicion q = p->sig;  
    
    if (q == NULL) {
        return 0;  
    }

    lNueva->raiz->sig=q->sig;
    lNueva->ultimo=lOrigen->ultimo;
    lOrigen->ultimo=q;
    lOrigen->ultimo->sig=NULL;

    return 0;
}
