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
	f = fopen("DatosListaElementosAleatorios.txt", "w+");
    fprintf(f,"n \t tiempoMedio \t ContadorExterno \t ContadorMedio \t ContadorInterno\n");
    printf("\n nº Elementos \t Tiempo \t Contador Externo \t Contador Medio \t Contador Interno");
	for(n=5000;n<=50000;n=5000+n){
		creaVacia(&miLista);
		
		anula(&miLista);	
		p = primero(&miLista);
		for (i = 0; i < n; i++) { 
			codigoError = inserta(rand()%100000,p,&miLista);
			p = siguiente(p,&miLista);
		}
		repeticiones=contadorInterno=contadorMedio=contadorExterno=0;
		tiempoInicial = tiempoFinal= (double)clock();
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


//  Lo que ocurre cuando se pasa a la función de inserción una lista con valores aleatorios, se comporta como el caso medio.
//  (Al haber introducido la condición de añadirse al final de la lista)
//  Se mete en algunas ocasiones en el bucle para buscar el lugar en la lista ordenada y otras veces se hace cierta la condición inicial 
//  y el elemento se introduce al final de la lista. 
//  Pero cuando se pasa una lista ordenada creciente o decreciente se comporta como el caso mejor.
//  Con la lista creciente ejecuta siempre el código que verifica que el primero de la desordenada que queremos introducir es mayor
//  que el último que se añadió en la ordenada, por tanto en el contadorInterno se incrementa solo una vez por elemento a introducido.
//  Y en el caso de la lista ordenada inversamente también se comporta como caso mejor debido a que siempre el primer elemento
//  de la lista desordenada va a ser menor al primer elemento de la ordenada, por lo que, se introducirá en la primera posición
//  de la ordenada en todas las inserciones. Haciendo que no se ejecute el bucle de buscar el lugar en la lista porque nunca es mayor,
// 	por ello el contadorInterno permanece a 0 al no entrar ni en el bucle ni en la condición de añadirse al final.
//
//  Tanto la lista ordenada creciente como la decreciente tendrán un comportamiento de orden n, mientras que con elementos aleatorios
//  será de orden n^2.
