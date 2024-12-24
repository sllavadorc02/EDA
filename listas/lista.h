#ifndef __LISTA_H
#define __LISTA_H

#ifndef __TIPO_ELEMENTO
#define __TIPO_ELEMENTO
typedef int tipoElemento;
#endif

#ifndef __TIPO_CELDA
#define __TIPO_CELDA
typedef struct tipoCelda {
	tipoElemento elemento;
	struct tipoCelda * sig;
} tipoCelda;
#endif

typedef struct {
	tipoCelda *raiz , *ultimo;
} Lista;

typedef tipoCelda *tipoPosicion;

extern long int contadorInterno, contadorExterno, contadorMedio;
int creaVacia(Lista *l);
int anula(Lista *l);
int vacia(Lista *l);

int inserta(tipoElemento x, tipoPosicion p, Lista *l);
int suprime (tipoPosicion p, Lista *l);
tipoPosicion localiza (tipoElemento x, Lista *l);
tipoElemento recupera(tipoPosicion p, Lista *l);

tipoPosicion primero(Lista *l);
tipoPosicion siguiente(tipoPosicion p, Lista *l);
tipoPosicion anterior(tipoPosicion p, Lista *l);
tipoPosicion fin(Lista *l);

void imprime(Lista *l);
int destruye(Lista *l);

tipoElemento recuperaUltimo(Lista *l);
int traspasarNodo(tipoPosicion p, Lista *la, tipoPosicion q, Lista *lb);
int dividirLista(Lista *lOrigen, tipoPosicion p, Lista *lNueva);
#endif
