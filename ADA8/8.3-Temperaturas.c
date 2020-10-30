/*Nombre Gener Alejandro Echeverria Chi
Fecha: 01/06/2020
a) Definir una estructura temperaturas definida por dos valores reales que indican las temperatura máxima y mínima. 
b) Crear una lista de 5 elementos de la estructura. 
c) Llenarlos con valores aleatorios que van de 0º a 40ºC.  
d) Llamar a un procedimiento que muestre las temperaturas de la lista en grados Farenheit. (ºF = ºC*9/5+32). 
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct temperatura{
	float maxima;
	float minima;
	struct temperatura* siguiente;
};
struct temperatura* cabecera=NULL;
void agregarTemperatura(float maxima, float minima);
void imprimirListaC();
void imprimirListaF(struct temperatura*);
int main(){
	int i;
	float aux, max,min;
	srand(time(NULL));
	for (i=0;i<5;i++){
		max=rand()%41;
		do {
			min=rand()%41;
		} while (min>=max);
	
		agregarTemperatura(max,min);
	}
	imprimirListaC();
	puts("-----------------------------");
	imprimirListaF(cabecera);	
	system("pause");
	return 0;
}
void agregarTemperatura(float maxima, float minima){
	struct temperatura* nuevo;
	struct temperatura* anterior;
	struct temperatura* actual;
	nuevo= (struct temperatura*)malloc(sizeof(struct temperatura));
	nuevo->maxima=maxima;
	nuevo->minima=minima;
	nuevo->siguiente=NULL;
	if (cabecera==NULL){
		cabecera=nuevo;
	}
	else {
		anterior=actual=cabecera;
		while (actual!=NULL){
			anterior=actual;
			actual=actual->siguiente;
		}
		anterior->siguiente=nuevo;
	}
}
void imprimirListaC(){
	struct temperatura* actual;
	actual=cabecera;
	puts("\tCENTIGRADOS");
	puts("MAXIMA\t\tMINIMA");
	while(actual!=NULL){
		printf("%.2lfC\t\t",actual->maxima);
		printf("%.2lfC\n",actual->minima);
		actual=actual->siguiente;
	}
}
void imprimirListaF(struct temperatura* cabecera){
	struct temperatura* actual;
	actual=cabecera;
	puts("\tFARENHEIT");
	puts("MAXIMA\t\tMINIMA");
	while(actual!=NULL){
		printf("%.2lfF\t\t",actual->maxima*9/5+32);
		printf("%.2lfF\n",actual->minima*9/5+32);
		actual=actual->siguiente;
	}
}


 
