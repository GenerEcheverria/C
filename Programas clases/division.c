//Division entera
#include<stdio.h>
int main(){
	int N;
	int D;
	int aux;
	int contador;
	
	//Entrada
	printf("Escribe el numerador: ");
	scanf("%i", &N);
	printf("Escribe el denominador: ");
	scanf("%i", &D);
	
	//Proceso
	aux=N;
	contador=0;
	while (aux>=D) {
		aux=aux-D;
		contador++;
	}
	
	//resultado
	printf("Resultado: %i", contador);
	return 0; 
}

