#include <stdio.h>
#include <stdlib.h>
#include "insercion.h"
#include <time.h>
#include "lista.h"

long int contadorInterno, contadorExterno, contadorMedio;

int main(int argc, char *argv[]){   
	Lista miLista;
	tipoPosicion p;
	int codigoError,i;
	double tiempo,tiempoInicial , tiempoFinal, tiempoMinimo=10*CLOCKS_PER_SEC;
	int n,repeticiones=0;
 	FILE *f;
	f = fopen("datos.txt", "w+");
    fprintf(f,"n \t tiempoMedio \t ContadorExterno \t ContadorMedio \t ContadorInterno\n");
    printf("\n nº Elementos \t Tiempo \t Contador Externo \t Contador Medio \t Contador Interno");
	for(n=5000;n<=50000;n=5000+n){
		creaVacia(&miLista);
		repeticiones=contadorInterno=contadorExterno=0;
		tiempoInicial = tiempoFinal= (double)clock();
		anula(&miLista);	
		p = primero(&miLista);
		for (i = 0; i < n; i++) { 
			codigoError = inserta(rand()%100000,p,&miLista);
			p = siguiente(p,&miLista);
		}
		insercion(&miLista);
		anula(&miLista);
		repeticiones++;
	    tiempoFinal = (double)clock();
        tiempo =  (tiempoFinal - tiempoInicial ) / CLOCKS_PER_SEC /repeticiones;
		printf("\n %d \t\t %e \t\t %ld \t\t\t %ld \t\t %ld", n,tiempo,contadorExterno/repeticiones,contadorMedio/repeticiones,contadorInterno/repeticiones);
		fprintf(f,"\n %d \t %e \t %ld \t %ld  \t %ld", n,tiempo,contadorExterno/repeticiones,contadorMedio/repeticiones,contadorInterno/repeticiones);


	}
	

	fclose(f);
	destruye(&miLista); 
	return 0;
}
