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
    int posicion;
    
    if (l == NULL || l->raiz == NULL) {
        return;
    }else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
            //printf("Valor: %d en posición: %d\n",aImprimir->elemento, posicion++);
            printf(" %d ",aImprimir->elemento);
            aImprimir = aImprimir->sig;
        }
//        printf("%d valores en la lista\n",posicion-1);
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
    tipoCelda *aux=l->raiz;
    if(l->raiz == NULL){
        return -1;
    }else{
        while(aux->sig != NULL ){
            aux=aux->sig;
        }

        l->ultimo=aux;
        
        return aux->elemento; 
    }

}


int traspasarNodo(tipoPosicion p, Lista *la, tipoPosicion q, Lista *lb){
    if(la == NULL || lb == NULL || p==NULL){
        return -1;
    }

    tipoCelda *aux1=la->raiz;
    tipoCelda *anterior1=NULL;
    int encontrado1=0;


    while(aux1!=NULL){
        if(aux1==p){
            encontrado1=1;
            break;
        }
        anterior1=aux1;
        aux1=aux1->sig;
    }

    if(encontrado1==0){
        return -2;
    }

    if(anterior1==NULL){
        la->raiz=aux1->sig;

    }else{
        anterior1->sig=aux1->sig;
    }


    if(la->ultimo==aux1){
        la->ultimo=anterior1;
    }


   

    if(lb->raiz==NULL){
        lb->raiz=aux1;
        aux1->sig=NULL;
        lb->ultimo=aux1;
    }else if(q==NULL){
        lb->ultimo->sig=aux1;
        aux1->sig=NULL;
        lb->ultimo=aux1;
    }else{
        tipoCelda *aux2=lb->raiz;
        tipoCelda *anterior2=NULL;
        int encontrado2=0;
        
        while(aux2!=NULL){
            if(aux2==q){
                encontrado2=1;
                break;
            }
            anterior2=aux2;
            aux2=aux2->sig;
        }
    

        if(encontrado2==0){
            return -2;
        }


        if(anterior2==NULL){
            aux1->sig=lb->raiz;
            lb->raiz=aux1;
        }else{
            anterior2->sig=aux1;
            aux1->sig=aux2;
        }


    }


    return 0;
}


int dividirLista(Lista *lOrigen, tipoPosicion p, Lista *lNueva){
    if(lOrigen->raiz ==NULL){
        return -1;
    }
    
    tipoCelda *aux=lOrigen->raiz;
    int encontrado=0;
    while(aux!=NULL){
        if(p==aux){
            encontrado=1;
            break;
        }

        aux=aux->sig;
    
    }

    if(encontrado==0){
        return -2;
    }

    
    
    tipoCelda *lista=lOrigen->raiz;
    lNueva->raiz=NULL;
    lNueva->ultimo=NULL;
    while(aux !=NULL){
        if(aux==p){
            lOrigen->ultimo=p;
            lOrigen->ultimo->sig=NULL;


            lNueva->raiz=p->sig;
            if(lNueva->raiz==NULL){
                lNueva->ultimo=NULL;
            }else{
                tipoCelda *temp= lNueva->raiz;
                while(temp->sig != NULL){
                    temp=temp->sig;
                }
                lNueva->ultimo=temp;

            }

            return 0;

        }

        aux=aux->sig;
    }
    

    //p no encontrado
    return -3;
    

}