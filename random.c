#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct temperatura{
	float maxima;
	float minima;
	struct temperatura* siguiente;
};
struct temperatura* cabecera=NULL;
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
void imprimirListaC(struct temperatura* cabecera){
	struct temperatura* actual;
	actual=cabecera;
	puts("Centigrados");
	while(actual!=NULL){
		printf("%.2lfC\n",actual->maxima);
		printf("%.2lfC\n\n",actual->minima);
		actual=actual->siguiente;
	}
}
void imprimirListaF(struct temperatura* cabecera){
	struct temperatura* actual;
	actual=cabecera;
	puts("Farenheit");
	while(actual!=NULL){
		printf("%.2lfF\n",actual->maxima*9/5+32);
		printf("%.2lfF\n\n",actual->minima*9/5+32);
		actual=actual->siguiente;
	}
}
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
	imprimirListaC(cabecera);
	imprimirListaF(cabecera);	
	system("pause");
	return 0;
}

